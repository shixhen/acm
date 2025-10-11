#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[20][20], num[20];

ll dfs(int pos, int last, bool lead, bool limit) {
    ll ans = 0;
    if (pos == 0) return 1;
    if (dp[pos][last] != -1 && !lead && !limit) {
        return dp[pos][last];
    }

    int up = limit ? num[pos] : 9;
    for (int i = 0; i <= up; ++i) {
        if (abs(i - last) < 2) continue; // 相邻数字不能相差小于2
        if (lead && i == 0) {
            ans += dfs(pos - 1, -2, true, limit && (i == up));
        } else {
            ans += dfs(pos - 1, i, false, limit && (i == up));
        }
    }
    if (!lead && !limit) {
        dp[pos][last] = ans;
    }
    return ans;


}

ll solve(ll x) {
    int len = 0;
    while (x) {
        num[++len] = x % 10ll;
        x /= 10ll;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(len, -2, true, true);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';


    return 0;
}