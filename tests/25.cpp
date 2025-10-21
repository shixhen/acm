#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i];
        y[i + 1] = y[i];
        if (s[i] == 'U') {
            y[i + 1]++;
        } else if (s[i] == 'D') {
            y[i + 1]--;
        } else if (s[i] == 'L') {
            x[i + 1]--;
        } else {
            x[i + 1]++;
        }
    }
    vector<pair<int, int>> p(m);
    for (auto &[xx, yy] : p) {
        cin >> xx >> yy;
    }
    map<pair<int, int>, int> mp1;
    map<pair<int, int>, vector<int>> mp2;
    int ans = 0;
    if (x[n] == 0 && y[n] == 0) {
        for (int i = 0; i <= n; i++) {
            mp1[{x[i], y[i]}] = 0;
        }
        for (auto &[xx, yy] : p) {
            mp2[{xx, yy}].push_back(0);
        }
        for (auto &[k, v] : mp1) {
            ans += mp2[{k.first, k.second}].size();
        }
        cout << ans << "\n";
        return;
    }
    if (x[n] != 0) {
        for (auto &[xx, yy] : p) {
            int tx = (xx % abs(x[n]) + abs(x[n])) % abs(x[n]);
            int t = (xx - tx) / x[n];
            int ty = yy - t * y[n];
            mp2[{tx, ty}].push_back(t);
        }
        for (int i = 0; i <= n; i++) {
            int tx = (x[i] % abs(x[n]) + abs(x[n])) % abs(x[n]);
            int t = (x[i] - tx) / x[n];
            int ty = y[i] - t * y[n];
            pair<int, int> it = {tx, ty};
            if (mp1.count(it)) {
                mp1[it] = min(mp1[it], t);
            } else {
                mp1[it] = t;
            }
        }
    } else {
        for (auto &[xx, yy] : p) {
            int ty = (yy % abs(y[n]) + abs(y[n])) % abs(y[n]);
            int t = (yy - ty) / y[n];
            int tx = xx - t * x[n];
            mp2[{tx, ty}].push_back(t);
        }
        for (int i = 0; i <= n; i++) {
            int ty = (y[i] % abs(y[n]) + abs(y[n])) % abs(y[n]);
            int t = (y[i] - ty) / y[n];
            int tx = x[i] - t * x[n];
            pair<int, int> it = {tx, ty};
            if (mp1.count(it)) {
                mp1[it] = min(mp1[it], t);
            } else {
                mp1[it] = t;
            }
        }
    }
    for (auto &[k, v] : mp1) {
        if (mp2.count(k)) {
            sort(mp2[k].begin(), mp2[k].end());
            auto it = lower_bound(mp2[k].begin(), mp2[k].end(), v);
            if (it != mp2[k].end()) {
                ans += mp2[k].size() - (it - mp2[k].begin());
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}