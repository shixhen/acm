#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> c(n + 1);
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> dep(n + 1);
    vector<vector<int>> f(n + 1, vector<int> (20));
    vector<vector<long long>> co(n + 1, vector<long long> (20));
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    function<void(int, int)> dfs = [&] (int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < 20; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        vector<long long> temp;
        for (auto v : edge[u]) {
            if (v != fa) {
                dfs(v, u);
                temp.push_back(c[v]);
            }
        }
        if (temp.size()) {
            sort(temp.begin(), temp.end());
            c[u] = min(c[u], temp[0] + temp[1]);
            for (auto v : edge[u]) {
                if (v == fa) continue;
                if (c[v] == temp[0]) {
                    co[v][0] = temp[1];
                } else {
                    co[v][0] = temp[0];
                }
            }
        }
    };
    dfs(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 2; j <= n; j++) {
            co[j][i] = co[j][i - 1] + co[f[j][i - 1]][i - 1];
        }
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        long long ans = 0;
        for (int j = 19; j >= 0; j--) {
            if (dep[f[x][j]] >= dep[y]) {
                ans += co[x][j];
                x = f[x][j];
            }
        }
        if (x != y) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}