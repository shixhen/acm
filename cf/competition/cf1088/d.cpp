#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1000000007LL;
constexpr int N = 100000;

long long fac[N + 1], ifac[N + 1];

long long mod_pow(long long a, long long t) {
    long long r = 1 % mod;
    while (t > 0) {
        if (t & 1) r = r * a % mod;
        a = a * a % mod;
        t >>= 1;
    }
    return r;
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = mod_pow(fac[N], mod - 2);
    for (int i = N; i >= 1; --i) ifac[i - 1] = ifac[i] * i % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> cnt(29, -1);
    for (int i = n; i >= 1; --i) {
        long long r = b[i];
        for (int b = 0; b < 29; ++b) {
            if (cnt[b] > i) {
                long long w = C(cnt[b], i);
                long long c = ((1LL << b) % mod) * w % mod;
                r -= c;
                if (r < 0) r += mod;
            }
        }
        r %= mod;

        for (int b = 0; b < 29; ++b) {
            if ((r >> b) & 1LL) cnt[b] = i;
        }
    }
    for (int b = 0; b < 29; ++b) {
        if (cnt[b] == -1) cnt[b] = 0;
    }

    vector<int> a(n, 0);
    for (int b = 0; b < 29; ++b) {
        for (int i = 0; i < cnt[b]; ++i) {
            a[i] |= (1 << b);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}