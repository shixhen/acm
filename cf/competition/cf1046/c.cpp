#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 2);
    vector<vector<int>> idx(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        idx[a[i]].push_back(i);
        if (idx[a[i]].size() >= a[i]) {
            dp[i] = max(dp[i], dp[idx[a[i]][idx[a[i]].size() - a[i]] - 1] + a[i]);
        }
        
    }
    cout << dp[n] << "\n";
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
