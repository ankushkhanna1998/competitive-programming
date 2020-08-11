class dsu {
public:

    int n;

    vector<int> p, sz;

    inline dsu(const int _n) : n(_n), p(_n), sz(_n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    inline int get(const int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline int size(const int x) {
        return sz[get(x)];
    }

    inline void unite(int x, int y) {
        if ((x = get(x)) != (y = get(y))) {
            if (sz[y] > sz[x]) {
                swap(x, y);
            }
            p[y] = x;
            sz[x] += sz[y];
        }
    }

};
