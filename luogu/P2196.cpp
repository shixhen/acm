#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x;
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<vector<int>> dp(25, vector<int>(n + 1));
    vector<vector<int>> last(25, vector<int>(n + 1));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> x;
            if (x == 1) {
                edge[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = a[i];
        last[0][i] = i;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j : edge[i]) {
                if (a[j] + dp[k - 1][j] > dp[k][i]) {
                    dp[k][i] = max(dp[k][i], a[i] + dp[k - 1][j]);
                    last[k][i] = j;
                }
            }
        }
    }
    vector<int> path;
    int idx = 0;
    int step = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                idx = j;
                step = i;
            }
        }
        
    }
    for (int i = step; i >= 0; i--) {
        if (idx == 0) break;
        cout << idx << ' ';
        idx = last[i][idx];
        
    }
    cout << '\n';
    cout << ans << '\n';
    return 0;
}