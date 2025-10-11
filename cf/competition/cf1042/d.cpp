#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> d(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    if (n == 2) {
        cout << "0\n";
        return;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            sum++;
        }
    }
    int cnt, ans = sum;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        for (auto &u: edge[i]) {
            if (d[u] == 1) {
                cnt++;
            }
        }
        ans = min(ans, sum - cnt);
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