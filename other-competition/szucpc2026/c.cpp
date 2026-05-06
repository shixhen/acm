#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;
constexpr long long N = 1e6 + 5;

long long pow2[N];
long long pow4[N];
long long cnt[N];

void init() {
    pow2[0] = 1;
    cnt[0] = 0;
    cnt[1] = 1;
    pow4[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2 % mod;
        pow4[i] = pow4[i - 1] * 4 % mod;
    }
    for (int i = 2; i < N; i++) {
        cnt[i] = (cnt[i - 1] * 4 % mod + pow2[i - 1]) % mod;
    }
}

void solve() {
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 1; i <= (int) s.size() - 2; i++) {
        ans += cnt[i];
        ans %= mod;
    }
    long long temp = 0;
    for (int i = 1; i < (int) s.size(); i++) {
        if (s[i] == '1') {
            long long add = (temp * 2 + 1) % mod * (pow4[(int) s.size() - i - 1]) % mod + cnt[(int)s.size() - i - 1];
            add %= mod;
            ans += add;
            ans %= mod;
            temp = (temp * 2) % mod;
        } else {
            temp = (temp * 2 + 1) % mod;
        }
    }
    ans = (ans + temp) % mod;
    cout << (ans + mod) % mod << "\n";
}


int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}