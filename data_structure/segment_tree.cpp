template <typename T>
class segment_tree {

private:

    int n;

    vector<T> tree, lazy;

    inline T unite(const T u, const T v) const {
        return (u + v);
    }

    inline void propagate(int v, int from, int to) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v] * (to - from + 1);
            if (from != to) {
                int tree_left = v << 1 | 1, tree_right = tree_left + 1;
                lazy[tree_left] += lazy[v];
                lazy[tree_right] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    inline void update(int v, int from, int to, int l, int r, const T delta) {
        propagate(v, from, to);
        if (from > to || from > r || to < l) {
            return;
        }
        int tree_left = v << 1 | 1, tree_right = tree_left + 1;
        if (from >= l && to <= r) {
            tree[v] += delta * (to - from + 1);
            if (from != to) {
                lazy[tree_left] += delta;
                lazy[tree_right] += delta;
            }
            return;
        }
        int coverage_mid = (from + to) >> 1;
        update(tree_left, from, coverage_mid, l, r, delta);
        update(tree_right, coverage_mid + 1, to, l, r, delta);
        tree[v] = unite(tree[tree_left], tree[tree_right]);
    }

    inline T query(int v, int from, int to, int l, int r) {
        propagate(v, from, to);
        if (from > to || from > r || to < l) {
            return static_cast<T>(0); // some "don't care" value
        }
        if (from >= l && to <= r) {
            return tree[v];
        }
        int coverage_mid = (from + to) >> 1;
        int tree_left = v << 1 | 1, tree_right = tree_left + 1;
        T left_query = query(tree_left, from, coverage_mid, l, r);
        T right_query = query(tree_right, coverage_mid + 1, to, l, r);
        return unite(left_query, right_query);
    }

public:

    inline segment_tree(const int _n) : n(_n), tree(_n << 2), lazy(_n << 2) {}

    template <typename A>
    inline segment_tree(const vector<A> a) : segment_tree((int) a.size()) {

        function<void(int, int, int)> build = [&](int v, int l, int r) -> void {
            if (l == r) {
                tree[v] = a[l];
                return;
            }
            int array_mid = (l + r) >> 1;
            int tree_left = v << 1 | 1, tree_right = tree_left + 1;
            build(tree_left, l, array_mid);
            build(tree_right, array_mid + 1, r);
            tree[v] = unite(tree[tree_left], tree[tree_right]);
        };

        build(0, 0, n - 1);
    }

    inline void update(const int l, const int r, const T delta) {
        update(0, 0, n - 1, l, r, delta);
    }

    inline T query(const int l, const int r) {
        return query(0, 0, n - 1, l, r);
    }

};
