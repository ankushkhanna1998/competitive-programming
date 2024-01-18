template <typename T>
inline vector<T> factorize(T n) {
  vector<T> res(__builtin_ctzll(n), 2);
  n >>= res.size();
  for (T i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      n /= i;
      res.push_back(i);
    }
  }
  if (n > 2) {
    res.push_back(n);
  }
  return res;
}

class factorizer {

private:

  const int MAXN;

  vector<int> spf;

public:

  inline factorizer(const int _n) : MAXN(_n), spf(_n + 1) {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 4; i <= MAXN; i += 2) {
      spf[i] = 2;
    }
    for (int i = 3; i * i <= MAXN; i += 2) {
      if (spf[i] == i) {
        for (int j = i * i; j <= MAXN; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
  }

  inline vector<int> factorize(int n) const {
    assert(0 < n && n <= MAXN);
    vector<int> res;
    while (n > 1) {
      res.push_back(spf[n]);
      n /= spf[n];
    }
    return res;
  }
};
