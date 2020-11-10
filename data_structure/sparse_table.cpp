template <typename T>
class sparse_table {

private:

    const T DEFAULT = static_cast<T>(0); // some "don't care" value

    int n;

    vector<T> a;
    vector<vector<T>> st_a, st_b;

    inline T unite(const T a, const T b) const {
        return (a + b);
    }

public:

    template <typename A>
    inline sparse_table(const vector<A> _a) : n((int) _a.size()),
                                              a(_a.begin(), _a.end()),
                                              st_a(32 - __builtin_clz(n)),
                                              st_b(st_a.size()) {
        for (int i = 0; i < (int) st_a.size(); i++) {
            int ones = (1 << i) - 1;
            T now = DEFAULT;
            st_a[i].resize(n);
            for (int j = 0; j < n; j++) {
                now = st_a[i][j] = unite(now, a[j]);
                if ((j & ones) == ones) {
                    now = DEFAULT;
                }
            }
            now = DEFAULT;
            st_b[i].resize(n);
            for (int j = n - 1; j >= 0; j--) {
                now = st_b[i][j] = unite(now, a[j]);
                if ((j & ones) == 0) {
                    now = DEFAULT;
                }
            }
        }
    }

    inline T query(const int from, const int to) const {
        if (from == to) {
            return unite(a[from], DEFAULT);
        }
        int lg = 32 - __builtin_clz(from ^ to) - 1;
        return unite(st_b[lg][from], st_a[lg][to]);
    }

};
