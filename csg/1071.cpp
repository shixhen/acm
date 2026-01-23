#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1e9 + 7;

vector<int> z_function(const vector<int> &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = n - 1; i >= 0; i--) {
            cin >> a[i];
        }
        vector<int> z = z_function(a);
        vector<int> max_len(m + 1, -1);
        for (auto x : a) max_len[x] = 0;
        for (int i = 1; i < n; i++) {
            int c = a[i - 1];
            if (z[i] > max_len[c]) {
                max_len[c] = z[i];
            }
        }
        long long ans = 0;
        long long pow3 = 1;
        for (int c = 1; c <= m; c++) {
            pow3 = (pow3 * 3) % mod;
            long long t;
            if (max_len[c] == -1) {
                t = n + 1;
            } else {
                t = n - max_len[c];
            }
            ans ^= (pow3 * t) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}