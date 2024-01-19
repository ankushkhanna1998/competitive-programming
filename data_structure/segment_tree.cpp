template <typename T>
class segment_tree {

private:

  const size_t n;
  const function<T(const T, const T)> unite;
  const T DEFAULT;

  vector<T> tree, lazy;

  template <typename A>
  inline void build(const vector<A> &a, const int v, const int l, const int r) {
    if (l == r) {
      tree[v] = static_cast<T>(a[l]);
      return;
    }
    const int array_mid = (l + r) >> 1;
    const int tree_left = v << 1 | 1, tree_right = tree_left + 1;
    build(a, tree_left, l, array_mid);
    build(a, tree_right, array_mid + 1, r);
    tree[v] = unite(tree[tree_left], tree[tree_right]);
  }

  inline void propagate(const int v, const int from, const int to) {
    if (lazy[v] != 0) {
      tree[v] += lazy[v] * (to - from + 1);
      if (from != to) {
        const int tree_left = v << 1 | 1, tree_right = tree_left + 1;
        lazy[tree_left] += lazy[v];
        lazy[tree_right] += lazy[v];
      }
      lazy[v] = 0;
    }
  }

  inline void update(const int v, const int from, const int to, const int l, const int r, const T delta) {
    propagate(v, from, to);
    if (to < l || r < from || to < from) {
      return;
    }
    const int tree_left = v << 1 | 1, tree_right = tree_left + 1;
    if (l <= from && to <= r) {
      tree[v] += delta * (to - from + 1);
      if (from != to) {
        lazy[tree_left] += delta;
        lazy[tree_right] += delta;
      }
      return;
    }
    const int coverage_mid = (from + to) >> 1;
    update(tree_left, from, coverage_mid, l, r, delta);
    update(tree_right, coverage_mid + 1, to, l, r, delta);
    tree[v] = unite(tree[tree_left], tree[tree_right]);
  }

  inline T query(const int v, const int from, const int to, const int l, const int r) {
    propagate(v, from, to);
    if (to < l || r < from || to < from) {
      return DEFAULT;
    }
    if (l <= from && to <= r) {
      return tree[v];
    }
    const int coverage_mid = (from + to) >> 1;
    const int tree_left = v << 1 | 1, tree_right = tree_left + 1;
    const T left_query = query(tree_left, from, coverage_mid, l, r);
    const T right_query = query(tree_right, coverage_mid + 1, to, l, r);
    return unite(left_query, right_query);
  }

public:

  inline segment_tree(const size_t _n,
                      const function<T(const T, const T)> &_unite = plus<T>(),
                      const T _default = 0) : n(_n),
                                              unite(_unite),
                                              DEFAULT(_default),
                                              tree(_n << 2, _default),
                                              lazy(_n << 2, _default) {}

  template <typename A>
  inline segment_tree(const vector<A> &a,
                      const function<T(const T, const T)> &_unite = plus<T>(),
                      const T _default = 0) : segment_tree(a.size(), _unite, _default) {
    build(a, 0, 0, (int) n - 1);
  }

  inline size_t size() const {
    return n;
  }

  inline void update(const int l, const int r, const T delta) {
    update(0, 0, (int) n - 1, l, r, delta);
  }

  inline T query(const int l, const int r) {
    return query(0, 0, (int) n - 1, l, r);
  }
};
