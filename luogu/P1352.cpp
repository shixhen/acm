#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, l, r;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> vis(n + 1);
    vector<array<int, 2>> f(n + 1, {0, 0});
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> l >> k;
        edge[k].push_back(l);
        vis[l] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            r = i;
            break;
        }
    }
    function<void(int)> dfs = [&](int u) {
        for (auto v : edge[u]) {
            dfs(v);
            f[u][0] += max(f[v][0], f[v][1]);
            f[u][1] += f[v][0];
        }
        f[u][1] += a[u];
        return;
    };
    dfs(r);
    cout << max(f[r][0], f[r][1]) << "\n";
    return 0;
}