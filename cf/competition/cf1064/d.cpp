#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long inv[5005];
long long fac[5005];

void init() {
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 5000; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
    fac[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int i = 1; i <= 5000; i++) {
        inv[i] = inv[i - 1] * inv[i] % mod;
    }
    return;
}

long long C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> cnt(5005, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    long long ans = 0;
    long long t;
    for (int len = n; len >= 1; len--) {
        
        
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}