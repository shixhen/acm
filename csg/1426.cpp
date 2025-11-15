#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, b;
    while (cin >> n >> b) {
        vector<vector<int>> dp(n + 1, vector<int>(b + 1, 0));
        vector<int> w(n + 1);
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= b; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }
        cout << dp[n][b] << "\n";
    }
    return 0;
}