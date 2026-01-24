#include <bits/stdc++.h>

using namespace std;



vector<string> g(5005);
int dp[5005][5005];
int num[5005][5005];
int num2[5005][5005];
int n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = ' ' + s;
        g[i] = s;
    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            num[i][j] = num[i][j - 1] + (g[i][j] == '#' ? 1 : 0);
        }
        for (int j = n; j >= 0; j--) {
            num2[i][j] = num2[i][j + 1] + (g[i][j] == '.' ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            // if (i == 3 && j == 2) {
            //     cout << dp[i - 1][j] << " " << num[i][j] << " " << num2[i][j + 1] << "\n";
            // }
            dp[i][j] = dp[i - 1][j] + num[i][j] + num2[i][j + 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    //cout << dp[3][2] << "\n";
    cout << dp[n][0] << "\n";
    return 0;
}