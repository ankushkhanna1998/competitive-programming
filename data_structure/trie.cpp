class trie {

private:

  const int K;

  struct vertex {

    int leaf, count;
    vector<int> next;

    inline vertex(const int _K) : leaf(0), count(0), next(_K, -1) {}
  };

  vector<vertex> t;

  inline int get_pos(const char c) const {
    // modify if required
    return tolower(c) - 'a';
  }

public:

  inline trie(const int _K = 26) : K(_K), t(1, vertex(_K)) {}

  inline void insert(const string &s) {
    int v = 0;
    for (const char c : s) {
      const int i = get_pos(c);
      if (t[v].next[i] == -1) {
        t[v].next[i] = (int) t.size();
        t.emplace_back(K);
      }
      t[v].count++;
      v = t[v].next[i];
    }
    t[v].count++;
    t[v].leaf++;
  }

  inline bool find(const string &s, const bool is_prefix = true) const {
    int v = 0;
    for (const char c : s) {
      const int i = get_pos(c);
      if (t[v].next[i] == -1) {
        return false;
      }
      v = t[v].next[i];
    }
    return (is_prefix ? t[v].count : t[v].leaf) > 0;
  }

  inline void erase(const string &s) {
    if (!find(s, false)) {
      return;
    }
    int v = 0;
    for (const char c : s) {
      const int i = get_pos(c);
      t[v].count--;
      v = t[v].next[i];
    }
    t[v].count--;
    t[v].leaf--;
  }

  inline bool empty() const {
    return t[0].count == 0;
  }

  inline size_t size() const {
    return (size_t) t[0].count;
  }

  inline size_t alphabet_size() const {
    return (size_t) K;
  }
};
