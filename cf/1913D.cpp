#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long qpow(long long t) {
    long long res = 1ll;
    long long base = 2ll;
    while (t) {
        if (t & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        t >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ls(n + 1), rs(n + 1);
    vector<int> lsize(n + 1), rsize(n + 1);
    vector<int> stk(n + 2);
    int top = 0;
    for (int i = 1; i <= n; i++) {
        int k = top;
        while (k && a[stk[k]] > a[i]) {
            k--;
        }
        if (k) {
            rs[stk[k]] = i;
        }
        if (k < top) {
            ls[i] = stk[k + 1];
        }
        stk[++k] = i;
        top = k;
    }
    function<int(int)> dfs = [&] (int u) -> int {
        if (u == 0) return 0;
        lsize[u] = dfs(ls[u]) + 1;
        rsize[u] = dfs(rs[u]) + 1;
        return lsize[u] + rsize[u] + 1;
    };
    dfs(stk[1]);
    vector<long long> dp(n + 1, 0);
    vector<long long> dpl(n + 1, 1), dpr(n + 1, 1);
    function<void(int)> dfs2 = [&] (int u) {
        if (u == 0) {
            return;
        }
        dfs2(ls[u]);
        dfs2(rs[u]);
        if (ls[u]) {
            dpl[u] = (dp[ls[u]] + dpl[ls[u]]) % mod;
        }
        if (rs[u]) {
            dpr[u] = (dp[rs[u]] + dpr[rs[u]]) % mod;
        }
        dp[u] = dpl[u] * dpr[u] % mod;
        //cout << u << " " << a[u] << " : " << dp[u] << '\n';
        return;
    };
    dfs2(stk[1]);
    cout << dp[stk[1]] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}