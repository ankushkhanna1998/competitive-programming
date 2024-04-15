template <typename T>
class fenwick_tree {

private:

  const int n;
  const function<T(const T, const T)> unite;
  const T DEFAULT;

  vector<T> fenw;

public:

  inline fenwick_tree(const int _n,
                      const function<T(const T, const T)> &_unite = plus<T>(),
                      const T _default = 0) : n(_n),
                                              unite(_unite),
                                              DEFAULT(_default),
                                              fenw(_n, _default) {}

  template <typename A>
  inline fenwick_tree(const vector<A> &a,
                      const function<T(const T, const T)> &_unite = plus<T>(),
                      const T _default = 0) : fenwick_tree(a.size(), _unite, _default) {
    for (int i = 0; i < n; i++) {
      update(i, a[i]);
    }
  }

  inline void update(int x, const T delta) {
    while (x < n) {
      fenw[x] += delta;
      x |= x + 1;
    }
  }

  inline int size() const {
    return n;
  }

  inline T query(int x) const {
    T res = DEFAULT;
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }

  inline T query(const int l, const int r) const {
    return query(r) - query(l - 1);
  }

  inline T order_of_key(const T val) const {
    return (val == 0 ? 0 : query(val - 1));
  }

  inline T find_by_order(const int pos) const {
    T res = DEFAULT;
    int low = 0, high = n - 1;
    while (low <= high) {
      const int mid = (low + high) >> 1;
      if (query(mid) >= pos + 1) {
        res = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return res;
  }
};
