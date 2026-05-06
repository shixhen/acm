#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int m = r - l + 1;
        vector<int> nxt(m);
        vector<int> best(m);
        vector<int> dp(m);
        long long ans = 0;
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && s[l + i] != s[l + j]) {
                j = nxt[j - 1];
            }
            if (s[l + i] == s[l + j]) {
                j++;
            }
            nxt[i] = j;

            if (j == 0) {
                best[i] = 0;
            } else if (nxt[j - 1] == 0) {
                best[i] = j;
            } else {
                best[i] = best[j - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            if (best[i] == 0) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - best[i]] + 1;
            }
            ans += dp[i];
        }
        cout << ans << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}