#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod = 998244353;
constexpr int MAXN = 200000;

long long inv[MAXN + 1];
long long f[MAXN + 1];

void init() {
    inv[0] = f[0] = f[1] = inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for (int i = 2; i <= MAXN; i++) {
        inv[i] = inv[i - 1] * inv[i] % mod;
    }
}

ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return f[n] * inv[m] % mod * inv[n - m] % mod;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum != n) {
        cout << "0\n";
        return;
    }
    int num = n;
    for (int i = 1; i <= n; i++) {
        if (a[i] > max(num, 0)) {
            cout << "0\n";
            return;
        }
        num -= 2;
    }
    ll ans = 1;
    int p = (n % 2 ? 1 : 2);
    sum = n;
    for (int i = (n + 1) / 2; i >= 1; i--) {
        //cout << ans << " " << p << "  " << a[i] << " " << C(p, a[i]) << "\n";
        ans *= C(p, a[i]);
        ans %= mod;
        p += 2;
        p -= a[i];
    }
    cout << ans << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}