template <typename T>
class sparse_table {

private:

  const int n;
  const function<T(const T, const T)> unite;
  const T DEFAULT;

  vector<T> a;
  vector<vector<T>> st_a, st_b;

public:

  template <typename A>
  inline sparse_table(const vector<A> &_a,
                      const function<T(const T, const T)> &_unite = plus<T>(),
                      const T _default = 0) : n(_a.size()),
                                              unite(_unite),
                                              DEFAULT(_default),
                                              a(_a.begin(), _a.end()),
                                              st_a(32 - __builtin_clz(n)),
                                              st_b(st_a.size()) {
    for (int i = 0; i < (int) st_a.size(); i++) {
      const int ones = (1 << i) - 1;
      T now = DEFAULT;
      st_a[i].resize(n, DEFAULT);
      for (int j = 0; j < n; j++) {
        now = st_a[i][j] = unite(now, a[j]);
        if ((j & ones) == ones) {
          now = DEFAULT;
        }
      }
      now = DEFAULT;
      st_b[i].resize(n, DEFAULT);
      for (int j = n - 1; j >= 0; j--) {
        now = st_b[i][j] = unite(now, a[j]);
        if ((j & ones) == 0) {
          now = DEFAULT;
        }
      }
    }
  }

  inline int size() const {
    return n;
  }

  inline T query(const int from, const int to) const {
    if (from == to) {
      return unite(a[from], DEFAULT);
    }
    const int lg = 32 - __builtin_clz(from ^ to) - 1;
    return unite(st_b[lg][from], st_a[lg][to]);
  }
};
