#include <bits/stdc++.h>

using namespace std;

int a[25][25];
int dp[25][20][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int x, y, v;
    while (1) {
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0) break;
        a[x][y] = v;
    }
    for (int k = 1; k <= n * 2 - 1; k++) {
        for (int i = 1; i <= n; i++) {
            int j = k - i + 1;
            if (j < 1 || j > n) continue;
            for (int m = 1; m <= n; m++) {
                int l = k - m + 1;
                if (l < 1 || l > n) continue;
                int &res = dp[k][i][m];
                auto &last = dp[k - 1];
                res = max(res, last[i][m]);
                if (i > 1) {
                    res = max(res, last[i - 1][m]);
                }
                if (m > 1) {
                    res = max(res, last[i][m - 1]);
                }
                if (i > 1 && m > 1) {
                    res = max(res, last[i - 1][m - 1]);
                }
                res += a[i][j];
                if (i != m) {
                    res += a[m][l];
                }
            }
        }
    }
    cout << dp[n * 2 - 1][n][n] << '\n';
    return 0;
}