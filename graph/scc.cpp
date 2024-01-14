class scc {

private:

  vector<bool> visited;
  vector<int> component;

  inline scc(const int n) : visited(n), comp_id(n, -1), g_rev(n) {}

  template <typename A>
  inline void dfs(const vector<vector<A>> &g, const int u) {
    visited[u] = true;
    for (const A vertex : g[u]) {
      const int v = static_cast<int>(vertex);
      if (!visited[v]) {
        dfs(g, v);
      }
    }
    component.push_back(u);
  }

  template <typename A>
  inline void clean(vector<A> &container) const {
    container.clear();
    container.shrink_to_fit();
  }

public:

  vector<int> comp_id;
  vector<vector<int>> g_rev, g_condensed;

  template <typename A>
  inline scc(const vector<vector<A>> &g) : scc((int) g.size()) {
    for (int u = 0; u < (int) g.size(); u++) {
      if (!visited[u]) {
        dfs(g, u);
      }
      for (const A v : g[u]) {
        g_rev[static_cast<int>(v)].push_back(u);
      }
    }
    visited.assign(g.size(), false);
    const vector<int> order(component.rbegin(), component.rend());
    for (const int i : order) {
      if (!visited[i]) {
        component.clear();
        dfs(g_rev, i);
        const int cur_id = (int) g_condensed.size();
        for (const int u : component) {
          comp_id[u] = cur_id;
          for (const int v : g_rev[u]) {
            if (comp_id[v] != cur_id && comp_id[v] != -1) {
              g_condensed[comp_id[v]].push_back(cur_id);
            }
          }
        }
        g_condensed.emplace_back();
      }
    }

    clean(visited);
    clean(component);
  }

  template <typename A, typename B>
  inline scc(const vector<vector<pair<A, B>>> &_g) {
    vector<vector<int>> g(_g.size());
    for (int u = 0; u < (int) g.size(); u++) {
      for (const auto &[v, _] : _g[u]) {
        g[u].push_back(static_cast<int>(v));
      }
    }
    *this = scc(g);
  }
};
