#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, b;
    cin >> n >> b;
    vector<int> dp(b + 1, 0);
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = b; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[b] << "\n";
    return 0;
}