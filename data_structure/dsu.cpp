class dsu {
public:

    vector<int> p, sz;
    int n;

    inline dsu(int _n) : n(_n) {
        sz.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[y] > sz[x]) {
                p[x] = y;
                sz[y] += sz[x];
            } else {
                p[y] = x;
                sz[x] += sz[y];
            }
            return true;
        }
        return false;
    }

};
