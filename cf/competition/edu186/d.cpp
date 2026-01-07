#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;
constexpr long long mod = 998244353;

long long fac[N], inv[N];

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
    for (int i = 1; i < N; i++) {
        inv[i] = inv[i - 1] * inv[i] % mod;
    }
}

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long sum = 0;
    for (auto &x : a) cin >> x, sum += x;
    long long cnt = sum % n;
    long long avg = sum / n;
    for (int i = 1; i <= n; i++) {
        if (a[i] > avg) {
            if (a[i] == avg + 1) {
                cnt--;
                if (cnt < 0) {
                    cout << "0\n";
                    return;
                }
            } else {
                cout << "0\n";
                return;
            }
        }
    }
    cnt = sum % n - cnt;
    cout << C(sum % n, cnt) * fac[cnt] % mod * fac[n - cnt] % mod << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}