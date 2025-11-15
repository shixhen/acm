#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> v;
    for (auto [x, y] : mp) {
        v.push_back({y, x});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    long long x = 0, y = 0, t;
    int st = 0;
    for (auto &[cnt, num] : v) {
        t = (num >> 1);
        if (st == 0) {
            y += (long long) t * cnt;
            x += (long long) (num - t) * cnt;
        } else {
            x += (long long) t * cnt;
            y += (long long) (num - t) * cnt;
        }
        if (num & 1) st ^= 1;
    }
    cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}