#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll maxn = 1e9 + 5;

ll qpow(ll a, ll t) {
    ll res = 1;
    while (t) {
        if (a > maxn) {
            return maxn;
        }
        if (t & 1) {
            res *= a;
            if (res > maxn) {
                return maxn;
            }
        }
        a *= a;
        t >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    ll n, y, m, nn, last1;
    cin >> t;
    while (t--) {
        cin >> n >> y >> m;
        vector<vector<int>> a(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) {
            cin >> nn;
            
            a[i].resize(nn + 1);
            for (int j = 1; j <= nn; j++) { cin >> a[i][j]; }
        }

        function<bool(ll x)> check1 = [&](ll x) -> bool {
            ll temp, tt;
            for (int i = 1; i <= n; i++) {
                temp = 0;
                for (int j = 1; j < a[i].size(); j++) {
                    if (a[i][j] >= x) return false;
                    tt = qpow(x, a[i].size() - j - 1);
                    temp += a[i][j] * tt;
                    if (temp > maxn) {
                        temp = maxn;
                    }
                }
                x = temp;
            }
            return x >= y;
        };
        function<bool(ll x)> check3 = [&](ll x) -> bool {
            ll temp, tt;
            for (int i = 1; i <= n; i++) {
                temp = 0;
                for (int j = 1; j < a[i].size(); j++) {
                    if (a[i][j] >= x) return false;
                    tt = qpow(x, a[i].size() - j - 1);
                    temp += a[i][j] * tt;
                    if (temp > maxn) {
                        temp = maxn;
                    }
                }
                x = temp;
            }
            return x > y;
        };
        ll l = 1, r = m + 5, mid;
        
        while (l < r) {
            mid = (l + r) >> 1;
            if (check1(mid))
                r = mid;
            else
                l = mid + 1;
        }
        ll ansl = r;
        l = 0, r = m + 1;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check3(mid))
                r = mid;
            else
                l = mid + 1;
        }
        ll ansr = r;
        if (ansr <= ansl || ansr <= 1 || ansl > m) {
            cout << "-1 -1\n";
        } else {
            cout << ansl << " " << ansr - 1 << "\n";
        }
    }

    return 0;
}