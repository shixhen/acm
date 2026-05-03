#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long fac[200005];
long long inv[200005];
long long inv_fac[200005];

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    inv_fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        inv_fac[i] = inv_fac[i - 1] * inv[i] % mod;
    }
}

long long C (int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * inv_fac[m] % mod * inv_fac[n - m] % mod;
}

vector<vector<int>> g;
int n, m;

vector<vector<long long>> dp;

long long calc1(int c) {
    dp[1][1] = 1;
    if (g[1][1] == c || g[n][m] == c) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = 0;
            if (g[i][j] == c) {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    return dp[n][m];
}

long long calc2(vector<pair<int, int>>& pos) {
    sort(pos.begin(), pos.end());
    vector<long long> d(pos.size());
    for (int i = 0; i < pos.size(); i++) {
        d[i] = C(pos[i].first + pos[i].second - 2, pos[i].first - 1) % mod;
        for (int j = 0; j < i; j++) {
            d[i] -= (d[j] * C(pos[i].first - pos[j].first + pos[i].second - pos[j].second, pos[i].first - pos[j].first) % mod);
            d[i] = (d[i] % mod + mod) % mod;
        }
    }
    return d.back();
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>(m + 1));
    dp.assign(n + 1, vector<long long>(m + 1));
    vector<int> cnt(n * m + 1);
    vector<vector<pair<int, int>>> pos(n * m + 1); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            cnt[g[i][j]]++;
            pos[g[i][j]].push_back({i, j});
        }
    }
    long long sum = C(n + m - 2, n - 1);
    //cout << sum << "\n";
    long long ans = 0;
    for (int i = 1; i <= n * m; i++) {
        if (!cnt[i]) continue;
        //cout << "Color " << i << ": " << cnt[i] << " positions\n";
        if ((long long) cnt[i] * (long long) cnt[i] > (long long) n * (long long) m) {
            ans += sum - calc1(i);
            ans %= mod;
            //cout << ans << "\n";
        } else {
            pos[i].push_back({n, m});
            //cout << i << " positions: " << calc2(pos[i]) << "\n";
            ans += sum - calc2(pos[i]);
            ans %= mod;
            //cout << ans << "-------\n";
        }
    }
    cout << (ans % mod + mod) % mod << "\n";
    return;
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