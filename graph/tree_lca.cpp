class tree_lca {

private:

    int max_height, time_elapsed;

    vector<int> in_time, out_time;
    vector<vector<int>> parent;
    vector<vector<int64_t>> dist;

    inline tree_lca(const int n) : max_height((int) ceil(log2(n))),
                                   time_elapsed(0), in_time(n), out_time(n),
                                   parent(n, vector<int>(1 + max_height)),
                                   dist(n, vector<int64_t>(1 + max_height)) {}

    template <typename A, typename B>
    void dfs(const vector<vector<pair<A, B>>> &g, const int u, const int p) {
        in_time[u] = ++time_elapsed;
        parent[u][0] = p;
        for (int i = 1; i <= max_height; i++) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
            dist[u][i] = dist[u][i - 1] + dist[parent[u][i - 1]][i - 1];
        }
        for (const pair<A, B> &edge : g[u]) {
            if (edge.first == p) {
                continue;
            }
            dist[edge.first][0] = static_cast<int64_t>(edge.second);
            dfs(g, edge.first, u);
        }
        out_time[u] = ++time_elapsed;
    }

public:

    template <typename A>
    inline tree_lca(const vector<vector<A>> &_g, const int root = 0)
                    : tree_lca((int) _g.size()) {
        vector<vector<pair<int, int>>> g(_g.size());
        for (int u = 0; u < (int) g.size(); u++) {
            for (const A v : _g[u]) {
                g[u].emplace_back(static_cast<int>(v), 1);
            }
        }
        dfs(g, root, root);
    }

    template <typename A, typename B>
    inline tree_lca(const vector<vector<pair<A, B>>> &_g, const int root = 0)
                    : tree_lca((int) _g.size()) {
        dfs(_g, root, root);
    }

    inline bool is_ancestor(const int u, const int v) const {
        return (in_time[u] <= in_time[v] && out_time[u] >= out_time[v]);
    }

    inline int lca(int u, const int v) const {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = max_height; i >= 0; i--) {
            if (!is_ancestor(parent[u][i], v)) {
                u = parent[u][i];
            }
        }
        return parent[u][0];
    }

    inline int64_t distance(const int u, const int v) const {
        return (dist[u][max_height] + dist[v][max_height]
                - (dist[lca(u, v)][max_height] << 1));
    }

};
