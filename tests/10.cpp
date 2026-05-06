#include <bits/stdc++.h>

using namespace std;

static const int MOD = 998244353;

inline void addmod(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    auto allow_zero = [&](int pos) -> bool {
        if (pos < 1 || pos > n) return true;
        return t[pos - 1] != '1';
    };

    auto allow_one = [&](int pos) -> bool {
        if (pos < 1 || pos > n) return false;
        return t[pos - 1] != '0';
    };

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int q = 0; q <= k; ++q) {
            int cur = dp[i][q];
            if (cur == 0) continue;

            // Frontier F means all final coordinates <= F are already decided.
            // Here F = i + 2*q - k.
            int F = i + 2 * q - k;
            char cs = s[i];

            // Put 0 at S[x]. Crosses only F+1, and it is not occupied in final state.
            if (cs != '1') {
                int y = F + 1;
                if (allow_zero(y)) {
                    addmod(dp[i + 1][q], cur);
                }
            }

            if (cs != '0') {
                // Put 1 at S[x] and keep it. Then final position is y = F+1.
                int y_keep = F + 1;
                if (allow_one(y_keep)) {
                    addmod(dp[i + 1][q], cur);
                }

                // Put 1 at S[x] and remove it in one operation.
                // This increases q by 1 and crosses F+1, F+2, F+3 as empty.
                if (q < k) {
                    int y1 = F + 1;
                    int y2 = F + 2;
                    int y3 = F + 3;
                    if (allow_zero(y1) && allow_zero(y2) && allow_zero(y3)) {
                        addmod(dp[i + 1][q + 1], cur);
                    }
                }
            }
        }
    }

    cout << dp[n][k] << '\n';
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