#include <bits/stdc++.h>

using namespace std;


int dp[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        a[i] %= m;
    }
    dp[l][(a[l] - a[0] + m) % m] = 0;
    
    for (int i = l; i <= n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 1; k < m; k++) {
                dp[i][k] = min({ dp[i][k], dp[i - j][(k - a[i] + a[i - j - 1] + m) % m], dp[i - j][(k - a[i] + a[i - j - 1] - 1 + 2 * m) % m] + 1});
            }
            dp[i][0] = min({ dp[i][0], dp[i - j][(0 - a[i] + a[i - j - 1] + m) % m], dp[i - j][(0 - a[i] + a[i - j - 1] - 1 + 2 * m) % m] + 1});
        }
    }
    cout << dp[n][0] << "\n";
    return 0;
}