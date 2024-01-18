template <typename T>
inline bool is_prime(const T n) {
  if (n < 9) {
    return n == 2 || n == 3 || n == 5 || n == 7;
  }
  if ((n & 1) == 0) {
    return false;
  }
  for (T i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

inline vector<int> sieve(const int n) {
  vector<bool> prime(n + 1, true);
  for (int i = 4; i <= n; i += 2) {
    prime[i] = false;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<int> res;
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      res.push_back(i);
    }
  }
  return res;
}
