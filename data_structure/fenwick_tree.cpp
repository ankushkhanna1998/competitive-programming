template <typename T>
class fenwick_tree {
public:

    int n;

    vector<T> fenw;

    inline fenwick_tree(int _n) : n(_n), fenw(_n) {}

    inline void add(int x, T delta) {
        while (x < n) {
            fenw[x] += delta;
            x |= x + 1;
        }
    }

    inline T sum(int x) {
        T res = static_cast<T>(0L);
        while (x >= 0) {
            res += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return res;
    }

};
