#include <bits/stdc++.h>

using namespace std;

long long qpow(long long a, long long t, long long mod) {
    long long res = 1;
    while (t) {
        if (t & 1) res = res * a % mod;
        a = a * a % mod;
        t >>= 1;
    }
    return res;
}

long long big_pow(const string &s, long long mod) {
    long long res = 1;
    for (auto &ch : s) {
        int d = ch - '0';
        res = qpow(res, 10, mod) * qpow(2, d, mod) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    vector<vector<int>> cycles;
    vector<int> ans(n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> cycle;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                cycle.push_back(cur);
                cur = a[cur];
            }
            cycles.push_back(cycle);
        }
    }
    map<long long, long long> mp;
    for (auto &cyc : cycles) {
        int len = (int) cyc.size();
        long long k;
        if (len == 1) {
            k = 0;
        } else {
            if (mp.count(len)) {
                k = mp[len];
            } else {
                k = big_pow(s, len);
                mp[len] = k;
            }
        }
        for (int j = 0; j < len; j++) {
            ans[cyc[j]] = cyc[(j + k) % len];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}