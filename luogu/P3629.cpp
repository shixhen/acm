#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, u, v, c, d1, d2;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<int> d(n + 1);
    vector<int> f(n + 1);
    vector<int> vis(n + 1);
    vector<int> dp(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : edge[u]) {
            if (v == fa) continue;
            f[v] = u;
            d[v] = d[u] + 1;
            if (d[v] > d[c]) {
                c = v;
            }
            dfs(v, u);
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (int v : edge[u]) {
            if (v == fa) continue;
            dfs2(v, u);
            c = max(c, dp[u] + dp[v] + (vis[u] && vis[v] ? -1 : 1));
            dp[u] = max(dp[u], dp[v] + (vis[u] && vis[v] ? -1 : 1));
        }
    };
    dfs(1, 0);
    d1 = c;
    d[c] = 0;
    dfs(c, 0);
    d2 = c;
    if (k == 1) {
        cout << 2 * n - 1 - d[c] << "\n";
        return 0;
    }
    for (int i = d2; i != d1; i = f[i]) {
        vis[i] = 1;
    }
    vis[d1] = 1;
    c = 0;
    dfs2(1, 0);
    cout << 2 * n - d[d2] - c << "\n";
    return 0;
}