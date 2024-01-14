class cut_points_edges {

private:

  int time_elapsed;
  vector<bool> visited;
  vector<int> in_time, min_time;

  inline cut_points_edges(const int n) : time_elapsed(0), visited(n),
                                         in_time(n), min_time(n) {}

  template <typename A>
  inline void dfs(const vector<vector<A>> &g, const int u, const int p) {
    visited[u] = true;
    in_time[u] = min_time[u] = ++time_elapsed;
    int children = 0;
    for (const A vertex : g[u]) {
      const int v = static_cast<int>(vertex);
      if (v == p) {
        continue;
      }
      if (visited[v]) {
        min_time[u] = min(min_time[u], in_time[v]);
      } else {
        children++;
        dfs(g, v, u);
        min_time[u] = min(min_time[u], min_time[v]);
        if (in_time[u] <= min_time[v]) {
          if (p != -1) {
            cut_points.push_back(u);
          }
          if (in_time[u] < min_time[v]) {
            bridges.emplace_back(u, v);
            if (u > v) {
              swap(bridges.back().first, bridges.back().second);
            }
          }
        }
      }
    }
    if (p == -1 && children > 1) {
      cut_points.push_back(u);
    }
  }

  template <typename A>
  inline void clean(vector<A> &container) const {
    container.clear();
    container.shrink_to_fit();
  }

public:

  vector<int> cut_points;
  vector<pair<int, int>> bridges;

  template <typename A>
  inline cut_points_edges(const vector<vector<A>> &g,
                          const bool keep_sorted = false)
                          : cut_points_edges((int) g.size()) {
    for (int u = 0; u < (int) g.size(); u++) {
      if (!visited[u]) {
        dfs(g, u, -1);
      }
    }
    if (keep_sorted) {
      sort(cut_points.begin(), cut_points.end());
      sort(bridges.begin(), bridges.end());
    }

    clean(visited);
    clean(in_time);
    clean(min_time);
  }

  template <typename A, typename B>
  inline cut_points_edges(const vector<vector<pair<A, B>>> &_g,
                          const bool keep_sorted = false) {
    vector<vector<int>> g(_g.size());
    for (int u = 0; u < (int) g.size(); u++) {
      for (const auto &[v, _] : _g[u]) {
        g[u].push_back(static_cast<int>(v));
      }
    }
    *this = cut_points_edges(g, keep_sorted);
  }
};
