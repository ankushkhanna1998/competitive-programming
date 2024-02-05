template <typename T>
inline vector<int> z_function(const int n, const T &s) {
  vector<int> z(n, n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
inline vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}
