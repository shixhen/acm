#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1);
    vector<vector<int>> temp(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    queue<int> q;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (temp[cur].empty()) temp[cur].push_back(cur);
        while (temp[cur].size() >= 2) {
            int s1 = temp[cur].back();
            temp[cur].pop_back();
            int s2 = temp[cur].back();
            temp[cur].pop_back();
            ans.push_back({s1, s2});
        }
        for (auto v : g[cur]) {
            if (ind[v] == 0) continue;
            ind[v]--;
            if (!temp[cur].empty()) {
                temp[v].push_back(temp[cur].back());
                temp[cur].pop_back();
            }
            if (ind[v] == 1) {
                q.push(v);
            }
        }
        if (!temp[cur].empty()) {
            ans.push_back({temp[cur].back(), cur});
            temp[cur].pop_back();
        }
        ind[cur] = 0;
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}