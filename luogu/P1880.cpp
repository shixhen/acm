#include <bits/stdc++.h>

using namespace std;


int dp[205][205];
int w[205][205];
int dp2[205][205];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    n <<= 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j - i + 1 > (n >> 1)) continue;
            for (int k = i; k <= j; k++) {
                w[i][j] += a[k];
            }
        }
        
    }
    for (int j = 2; j <= n; j++) {
        for (int i = j - 1; i >= 1; i--) {
            if (i - j + 1 > (n >> 1)) continue;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + w[i][j]);
            }
        }
    }
    n >>= 1;
    int ans1 = INT_MAX;
    int ans2 = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ans1 = min(ans1, dp[i][i + n - 1]);
        ans2 = max(ans2, dp2[i][i + n - 1]);
    }

    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}