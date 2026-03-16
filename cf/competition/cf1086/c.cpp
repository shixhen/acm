#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1), p(n + 1);
    vector<double> dp(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> p[i];
    }
    for (int i = n; i >= 1; i--) {
        dp[i] = max(dp[i + 1], c[i] + (1 - p[i] / 100.0) * dp[i + 1]);
    }
    cout << fixed << setprecision(10) << dp[1] << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}