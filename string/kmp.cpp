template <typename T>
inline vector<int> kmp_table(const int n, const T &s) {
  vector<int> lps(n);
  for (int i = 1, j = 0; i < n; i++) {
    while (j > 0 && s[i] != s[j]) {
      j = lps[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    lps[i] = j;
  }
  return lps;
}

template <typename T>
inline vector<int> kmp_table(const T &s) {
  return kmp_table((int) s.size(), s);
}

template <typename T>
inline vector<int> kmp_search(const int n, const T &source, const int m, const T &search, const vector<int> &lps) {
  assert(m > 0 && (int) lps.size() == m);
  vector<int> occurrences;
  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && (j == m || source[i] != search[j])) {
      j = lps[j - 1];
    }
    if (source[i] == search[j]) {
      j++;
    }
    if (j == m) {
      occurrences.push_back(i - m + 1);
    }
  }
  return occurrences;
}

template <typename T>
inline vector<int> kmp_search(const int n, const T &source, const int m, const T &search) {
  return kmp_search(n, source, m, search, kmp_table(m, search));
}

template <typename T>
inline vector<int> kmp_search(const T &source, const T &search, const vector<int> &lps) {
  return kmp_search((int) source.size(), source, (int) search.size(), search, lps);
}

template <typename T>
inline vector<int> kmp_search(const T &source, const T &search) {
  return kmp_search((int) source.size(), source, (int) search.size(), search, kmp_table(search));
}
