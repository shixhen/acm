#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> temp;
vector<pair<int, int>> ans;

void dfs(int u, int fa) {
    for (auto &v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    if (temp[u].empty()) temp[u].push_back(u);
    while (temp[u].size() >= 2) {
        int s1 = temp[u].back();
        temp[u].pop_back();
        int s2 = temp[u].back();
        temp[u].pop_back();
        ans.push_back({s1, s2});
    }
    if (!temp[u].empty()) {
        temp[fa].push_back(temp[u][0]);
    }
    return;
}

void solve() {
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    temp.assign(n + 1, vector<int>());
    ans.clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    if (!temp[1].empty()) {
        ans.push_back({temp[1][0], 1});
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}