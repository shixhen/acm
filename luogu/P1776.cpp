#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, W;
    cin >> n >> W;
    vector<int> dp(W + 1);
    int v, w, m;
    while (n--) {
        cin >> v >> w >> m;
        int k = 1;
        while (m > k) {
            for (int i = W; i >= w * k; i--) {
                dp[i] = max(dp[i], dp[i - w * k] + v * k);
            }
            m -= k;
            k <<= 1;
        }
        for (int i = W; i >= w * m; i--) {
            dp[i] = max(dp[i], dp[i - w * m] + v * m);
        }
    }
    cout << dp[W];
    return 0;
}