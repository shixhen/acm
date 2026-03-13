#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
    }

    vector<long long> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }

    long long ans = 0;
    vector<long long> dp(n + 1, 0);      
    vector<long long> good(n + 1, 0);   
    vector<long long> sumL(n + 1, 0);  
    long long sumR = 0;                 

    int last = 0;  
    for (int i = 1; i <= n; i++) {
        if (pref[i - 1] < 2) {
            last = i - 1;
        }
        long long addL = (sumL[i - 1] - sumL[last] + mod) % mod;

        if (s[i] == '(') {
            good[i] = (1 + sumR + addL) % mod;
            sumL[i] = (sumL[i - 1] + good[i]) % mod;
            ans = (ans + pow2[i - 1]) % mod;
        } else {
            dp[i] = (1 + sumR + addL) % mod;
            sumR = (sumR + dp[i]) % mod;
            ans = (ans + dp[i]) % mod;
            sumL[i] = sumL[i - 1];
        }
    }
    cout << ans << "\n";
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