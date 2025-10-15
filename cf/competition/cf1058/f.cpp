#include <bits/stdc++.h>

using namespace std;
constexpr long long mod = 1e9 + 7;
constexpr int N = 4e5 + 5;

long long fac[N], ifac[N];
long long pow2[N], inv2[N];
long long inv[N];

void init() {
    fac[0] = ifac[0] = 1;
    pow2[0] = inv2[0] = 1;
    inv[1] = 1;

    // 1. 计算 i 的逆元 inv[i]
    for (int i = 2; i < N; i++)
        inv[i] = mod - mod / i * inv[mod % i] % mod;

    // 2. 计算阶乘 fac[i]
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;

    // 3. 计算阶乘的逆元 ifac[i] = ifac[i-1] * inv[i]
    for (int i = 1; i < N; i++)
        ifac[i] = ifac[i - 1] * inv[i] % mod;

    // 4. 计算 2 的幂和其逆元幂
    long long inv_2 = (mod + 1) / 2; // 因为 mod 是奇数
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2 % mod;
        inv2[i] = inv2[i - 1] * inv_2 % mod;
    }
}

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    set<int> s;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1 && a[i] && s.count(a[i])) {
            cout << "0\n";
            return;
        }
        s.insert(a[i]);
        if (a[i] != -1 && a[i] != 0) {
            if (a[a[i]] != i && a[a[i]] != -1) {
                cout << "0\n";
                return;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (a[i] != -1) {
            a[a[i]] = i;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) cnt++;
    }
    //cout << cnt << "\n";
    if (cnt == 0) {
        cout << "1\n";
        return;
    }
    long long ans = 0, k;
    for (int i = 0; i <= cnt; i += 2) {
        // 从 cnt 个位置中选 i 个位置两两配对
        k = C(cnt, i) * fac[i] % mod * inv2[i / 2] % mod * ifac[i / 2] % mod;
        //cout << k << "\n";
        k = (k * pow2[cnt - i]) % mod;
        //cout << i << " " << k << "\n";
        if (a[n] == -1)
            k = k - C(cnt - 1, i) * pow2[cnt - i - 1] % mod + mod % mod;
        //cout << i << " " << k << "\n";
        ans = ((ans + k) % mod);
    }
    cout << ans << "\n";
    return;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}