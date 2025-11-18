#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string t;
    cin >> n >> t;
    if (t.size() == 1) {
        cout << 1;
        return 0;
    }
    vector<int> nxt(t.size());
    vector<int> dp(t.size() + 1);
    long long ans = 0;
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
        if (nxt[i] && dp[nxt[i] - 1] == 0) {
            dp[i] = j;
        } else if (nxt[i]) {
            dp[i] = dp[nxt[i] - 1];
        }
        if (dp[i]) {
            ans += i + 1 - dp[i];
        }
    }
    cout << ans << "\n";
    return 0;
}