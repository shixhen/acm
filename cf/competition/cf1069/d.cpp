#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = max(a[i], a[i - 1]);
    }
    int ans = 0;
    // max, sum
    vector<vector<int>> dp(k + 2, vector<int>(k + 2));
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        for (int j = a[i - 1]; j <= a[i]; j++) {
            for (int s = j; s <= k; s++) {
                for (int m = 0; m < j; m++) {
                    dp[j][s] = max(dp[j][s], dp[m][s - j] + (n - i + 1) * (j - m));
                    ans = max(ans, dp[j][s]);
                }
            }
        }
    }
    // for (int i = 0; i <= k; i++) {
    //     cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    // }
    cout << ans << "\n";
    return;
}

int main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}