#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> dp;
vector<int> d;
int k;

void dfs(int u, int f) {
    if (d[u] == 1) {
        dp[u] = 0;
        return;
    }
    vector<int> temp;
    for (auto x : g[u]) {
        if (x == f) {
            continue;
        }
        dfs(x, u);
        temp.push_back(dp[x] + 1);
    }
    sort(temp.begin(), temp.end());
    if (temp.size() >= 2 && temp[0] + temp[1] <= k + 1) {
        dp[u] = 0;
    } else {
        dp[u] = temp[0];
    }
    return;
}

void solve() {
    int n, ve;
    cin >> n >> k >> ve;
    g.assign(n + 1, vector<int>());
    d.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(ve, 0);
    cout << ((dp[ve] == 0) ? "Yes" : "No") << "\n";
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