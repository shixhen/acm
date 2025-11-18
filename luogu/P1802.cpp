#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    int l, w, u;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> l >> w >> u;
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j] + l;
            if (j >= u) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - u] + w);   
        }
    }
    cout << (long long) dp[n][x] * 5ll << '\n';
    return 0;
}