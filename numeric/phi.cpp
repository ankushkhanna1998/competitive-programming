template <typename T>
inline T phi(T n) {
  T ans = n;
  n >>= __builtin_ctzll(n);
  if (ans != n) {
    ans >>= 1;
  }
  for (T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      ans -= ans / i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 2) {
    ans -= ans / n;
  }
  return ans;
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
