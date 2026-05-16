#include <bits/stdc++.h>

using namespace std;

bool is_match(char l, char r) {
    return (l == '(' && r == ')') ||
           (l == '[' && r == ']') ||
           (l == '{' && r == '}');
}

int main() {
    string s;
    while (cin >> s) {
        int n = (int)s.size();
        if (n == 0) {
            cout << "SZTU_WOD YYDS!" << endl;
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                int best = INT_MAX;

                if (is_match(s[l], s[r])) {
                    best = (len == 2 ? 0 : dp[l + 1][r - 1]);
                }

                for (int k = l; k < r; k++) {
                    best = min(best, dp[l][k] + dp[k + 1][r]);
                }

                dp[l][r] = best;
            }
        }

        int ans = dp[0][n - 1];
        if (ans == 0) {
            cout << "SZTU_WOD YYDS!" << endl;
        } else {
            cout << ans << endl;
        }
    }
}