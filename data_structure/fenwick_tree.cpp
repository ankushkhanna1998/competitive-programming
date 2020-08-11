template <typename T>
class fenwick_tree {
public:

    int n;

    vector<T> fenw;

    inline fenwick_tree(const int _n) : n(_n), fenw(_n) {}

    template <typename A>
    inline fenwick_tree(const vector<A> a) : fenwick_tree((int) a.size()) {
        for (int i = 0; i < n; i++) {
            add(i, a[i]);
        }
    }

    inline void add(int x, const T delta) {
        while (x < n) {
            fenw[x] += delta;
            x |= x + 1;
        }
    }

    inline T sum(int x) const {
        T res = 0;
        while (x >= 0) {
            res += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return res;
    }

    inline T sum(const int l, const int r) const {
        return sum(r) - sum(l - 1);
    }

    inline int order_of_key(const T val) const {
        return (val == 0 ? 0 : (int) sum(val - 1));
    }

    inline T find_by_order(const int pos) const {
        T res = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (sum(mid) >= pos + 1) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

};
