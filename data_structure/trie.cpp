template <typename T>
class trie {

private:

  typedef typename T::value_type key_type;
  typedef unordered_map<key_type, int> next_table;
  typedef typename next_table::const_iterator vertex_pointer;

  struct vertex {

    int leaf, count;
    next_table next;
  };

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

public:

  inline trie() : tree(1) {}

  inline void insert(const T &s) {
    int v = 0;
    for (const key_type c : s) {
      tree[v].count++;
      v = put_next(tree[v], c);
    }
    tree[v].count++;
    tree[v].leaf++;
  }

  inline bool find(const T &s, const bool is_prefix = true) const {
    int v = 0;
    for (const key_type c : s) {
      const int nxt = get_next(tree[v], c);
      if (nxt == -1) {
        return false;
      }
      v = nxt;
    }
    return (is_prefix ? tree[v].count : tree[v].leaf) > 0;
  }

  inline bool erase(const T &s) {
    if (!find(s, false)) {
      return false;
    }
    int v = 0;
    for (const key_type c : s) {
      tree[v].count--;
      v = get_next(tree[v], c);
    }
    tree[v].count--;
    tree[v].leaf--;
    return true;
  }

  inline bool empty() const {
    return tree[0].count == 0;
  }

  inline size_t size() const {
    return (size_t) tree[0].count;
  }
};
