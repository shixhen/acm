#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[1] != 1 && a[1] != 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        // [i ,m - i + 1]
        if (a[i] != 0 && (a[i] < i || a[i] > m - n + i)) {
            cout << "0\n";
            return;
        }
    }
    vector<int> ndp(m + 1);
    vector<int> odp(m + 1);
    vector<vector<int>> d(m + 1, vector<int>());
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            if (__gcd(i, j) == i - j) {
                d[j].push_back(i);
            }
        }
    }
    ndp[1] = 1;
    for (int i = 2; i <= n; i++) {
        swap(ndp, odp);
        fill(ndp.begin(), ndp.end(), 0);
        if (a[i]) {
            for (int j = 1; j < m; j++) {
                if (__gcd(j, a[i]) == a[i] - j) {
                    ndp[a[i]] = (ndp[a[i]] + odp[j]) % mod;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                for (auto x : d[j]) {
                    ndp[x] = (ndp[x] + odp[j]) % mod;
                }
            }
        }
        // for (int j = 1; j <= m; j++) {
        //     cout << ndp[j] << " ";
        // }
        // cout << "\n";
    }
    int ans = 0;
    for (auto i : ndp) {
        ans = (ans + i) % mod;
    }
    cout << ans << "\n";

    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--) {
        solve();
    }


    return 0;
}