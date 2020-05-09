template <typename T>
class sparse_table {

private:

    int n;

    vector<vector<T>> st;

    inline T unite(T a, T b) const {
        return min(a, b);
    }

public:

    template <typename A>
    inline sparse_table(const vector<A> a) : n(static_cast<int>(a.size())) {
        st.resize(32 - __builtin_clz(n));
        st[0].assign(a.begin(), a.end());
        for (int i = 1; i < (int) st.size(); i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < (int) st[i].size(); j++) {
                st[i][j] = unite(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    inline T query(int from, int to) const {
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return unite(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }

};
