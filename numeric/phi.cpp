template <typename T>
inline T phi(T n) {
  T result = n;
  n >>= __builtin_ctzll(n);
  if (result != n) {
    result >>= 1;
  }
  for (T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      result -= result / i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 2) {
    result -= result / n;
  }
  return result;
}

inline vector<int> phi_all(const int n) {
  vector<int> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  return phi;
}
