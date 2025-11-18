#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (int i = n / 2; i < n; i++) {
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end(), cmp);
    vector<pair<int, int>> c;
    for (int i = 0; i < n / 2; i++) {
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    int p = n / 2 - 1;
    int i;
    ll ans = 0;
    for (i = 0; i < c.size(); i++) {
        if (p && a[p].second - c[i].first > 0) {
            p--;
            ans += a[p].second - c[i].first;
        } else {
            break;
        }
    }
    p = 0;
    for (; i < c.size(); i++) {
        ans += c[i].second - a[p].first;
        p++;
    }
    for (int i = 0; i < n; i++) {
        ans += a[i].second - a[i].first;
    }
    cout << ans << "\n";
    return;
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