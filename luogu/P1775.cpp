#include <bits/stdc++.h>

using namespace std;

constexpr int N = 305;

int dp[N][N];   // dp[i][j]表示合并区间[i,j]的最小代价
int w[N][N];    // w[i][j]表示从i到j的权值和

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                w[i][j] += a[k];
            }
        }
    }
    for (int j = 2; j <= n; j++) {
        for (int i = j - 1; i >= 1; i--) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
            }
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}