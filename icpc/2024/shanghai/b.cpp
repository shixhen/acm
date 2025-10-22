#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1, vector<int>());
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<pair<int, int>> edge(m);
    vector<pair<int, int>> ans;
    for (auto &[u, v] : edge) {
        cin >> u >> v;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[b[i]] = i;
    }
    for (auto &[u, v] : edge) {
        e[a[u]].push_back(a[v]);
        e[a[v]].push_back(a[u]);
    }
    int p = 1;
    const auto dfs = [&] (auto &&self, int u) -> void {
        p++;
        sort(e[u].begin(), e[u].end());
        for (auto v : e[u]) {
            if (v < p) continue;
            while (p < v) {
                ans.push_back({u, p});
                self(self, p);
            }
            if (p == v) {
                self(self, p);
            }
        }
    };
    while (p <= n) {
        dfs(dfs, p);
    }
    cout << ans.size() << "\n";
    for (auto &[u, v] : ans) {
        cout << b[u] << " " << b[v] << "\n";
    }
    return 0;
}