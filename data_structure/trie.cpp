template <typename T>
class trie {

private:

  typedef T::value_type key_type;
  typedef unordered_map<key_type, int> next_table;
  typedef next_table::const_iterator vertex_pointer;

  struct vertex {

    int leaf, count;
    next_table next;

    inline vertex() : leaf(0), count(0), next() {}
  };

  int unique_prefixes, unique_strings;
  vector<vertex> tree;

  inline int get_next(const vertex &v, const key_type c) const {
    const vertex_pointer ptr = v.next.find(c);
    return (ptr == v.next.end() ? -1 : ptr->second);
  }

  inline int put_next(vertex &v, const key_type c) {
    int i = get_next(v, c);
    if (i == -1) {
      i = (int) tree.size();
      v.next.emplace(c, i);
      tree.emplace_back();
    }
    return i;
  }

  inline void update_counts(const int v, const int n, const bool is_prefix) {
    int &cnt = (is_prefix ? tree[v].count : tree[v].leaf);
    int &uniques = (is_prefix ? unique_prefixes : unique_strings);
    cnt += n;
    if (cnt == 0) {
      uniques--;
    } else if (cnt == n) {
      uniques++;
    }
  }

  inline void update(const T &s, const int copies) {
    int v = 0;
    for (const key_type c : s) {
      v = put_next(tree[v], c);
      update_counts(v, copies, true);
    }
    if (v != 0) {
      update_counts(v, copies, false);
      tree[0].count += copies;
    }
  }

public:

  inline trie() : unique_prefixes(0), unique_strings(0), tree(1) {}

  inline void insert(const T &s, const int copies = 1) {
    assert(copies > 0);
    update(s, copies);
  }

  inline int count(const T &s, const bool is_prefix = true) const {
    int v = 0;
    for (const key_type c : s) {
      const int nxt = get_next(tree[v], c);
      if (nxt == -1) {
        return 0;
      }
      v = nxt;
    }
    return (v == 0 ? 0 : (is_prefix ? tree[v].count : tree[v].leaf));
  }

  inline bool find(const T &s, const bool is_prefix = true) const {
    return count(s, is_prefix) != 0;
  }

  inline bool erase(const T &s, const int copies = 1) {
    const int cnt = count(s, false);
    if (cnt == 0) {
      return false;
    }
    assert(copies > 0);
    update(s, -min(copies, cnt));
    return true;
  }

  inline bool empty() const {
    return tree[0].count == 0;
  }

  inline int size() const {
    return tree[0].count;
  }

  inline int unique_count(const bool is_prefix = false) const {
    return (is_prefix ? unique_prefixes : unique_strings);
  }
};
