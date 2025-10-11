#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int W, n;
    cin >> W >> n;
    int S = (1 << n);
    vector<int> ts(S), ws(S);
    for (int j = 0, t, w; j < n; j++) {
        cin >> t >> w;
        for (int i = 0; i < S; i++) {
            if (i >> j & 1) {
                ts[i] = max(ts[i], t);
                ws[i] += w;
            }
        }
    }
    vector<int> dp(S, 0x3f3f3f3f);
    for (int i = 0; i < S; i++) {
        if (ws[i] <= W) dp[i] = ts[i];
        for (int j = i; j; j = (j - 1) & i) {
            if (ws[i ^ j] <= W) {
                dp[i] = min(dp[i], dp[j] + ts[i ^ j]);
            }
        }
    }
    cout << dp[S - 1] << "\n";

    return 0;
}