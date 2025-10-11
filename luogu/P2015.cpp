#include <bits/stdc++.h>

using namespace std;


struct Edge {
    int to, w;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q, u, v, w;
    cin >> n >> q;
    vector<vector<int>> dp(n + 1, vector<int>(q + 1, 0));
    vector<vector<Edge>> edges(n + 1);
    vector<int> sz(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    const function<void(int, int)> dfs = [&] (int u, int fa) -> void {
        for (const auto& edge : edges[u]) {
            int v = edge.to, w = edge.w;
            if (v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v] + 1;
            for (int j = min(sz[u], q); j; j--) {
                for (int k = min(sz[v], j - 1); k >= 0; k--) {
                    dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + w);
                }
            }
        }
    };
    dfs(1, 0);
    cout << dp[1][q] << "\n";
    return 0;
}