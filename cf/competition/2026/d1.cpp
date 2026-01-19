#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> s;
vector<int> dep;

void dfs(int u, int fa) {
    s[u] = 1;
    for (auto v : g[u]) {
        if (v == fa) {
            continue;
        }
        dep[v] = dep[u] + 1;
        s[u]++;
        dfs(v, u);
        
    }
}

void solve() {
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    dep.assign(n + 1, 0);
    s.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[dep[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, cnt[i]);
        ans = max(ans, s[i]);
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}