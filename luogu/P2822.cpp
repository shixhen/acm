#include <bits/stdc++.h>

using namespace std;


int c[2002][2002];
int dp[2002][2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, k;
    cin >> t >> k;
    for (int i = 0; i <= 2000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= k;
        }
    }
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            if (c[i][j] == 0 and j < i) {
                dp[i][j] = 1;
            }
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
    return 0;
}