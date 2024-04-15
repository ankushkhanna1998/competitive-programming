template <typename T>
inline vector<T> factorize(T n) {
  vector<T> factors(__builtin_ctzll(n), 2);
  n >>= factors.size();
  for (T i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      n /= i;
      factors.push_back(i);
    }
  }
  if (n > 2) {
    factors.push_back(n);
  }
  return factors;
}

class factorizer {

private:

  const int MAX_N;

  vector<int> spf;

public:

  inline factorizer(const int _n) : MAX_N(_n), spf(_n + 1) {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 4; i <= MAX_N; i += 2) {
      spf[i] = 2;
    }
    for (int i = 3; i * i <= MAX_N; i += 2) {
      if (spf[i] == i) {
        for (int j = i * i; j <= MAX_N; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
  }

  inline vector<int> factorize(int n) const {
    assert(0 < n && n <= MAX_N);
    vector<int> factors;
    while (n > 1) {
      factors.push_back(spf[n]);
      n /= spf[n];
    }
    return factors;
  }
};
