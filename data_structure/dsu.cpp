class dsu {

private:

  const size_t n;

  int components;
  vector<int> p, sz;

public:

  inline dsu(const size_t _n) : n(_n), components(_n), p(_n), sz(_n, 1) {
    iota(p.begin(), p.end(), 0);
  }

  inline size_t size() const {
    return n;
  }

  inline int get_components() const {
    return components;
  }

  inline int get_parent(const int x) {
    return (x == p[x] ? x : (p[x] = get_parent(p[x])));
  }

  inline void unite(int x, int y) {
    if ((x = get_parent(x)) != (y = get_parent(y))) {
      if (sz[x] < sz[y]) {
        swap(x, y);
      }
      p[y] = x;
      sz[x] += sz[y];
      components--;
    }
  }

  inline int get_size(const int x) {
    return sz[get_parent(x)];
  }
};
