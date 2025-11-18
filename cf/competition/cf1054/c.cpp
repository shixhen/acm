#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnta = 0, cntb = 0;
    for (auto &c : s) {
        if (c == 'a') cnta++;
        else cntb++;
    }
    int p1 = 0, p2 = cnta;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a.push_back({p1, i});
            p1++;
        } else {
            a.push_back({p2, i});
            p2++;
        }
    }
    ll ans1 = 0, ans2 = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ans1 += abs(a[i].second - i);
    }
    ans1 >>= 1;
    p1 = 0, p2 = cntb;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            b.push_back({p1, i});
            p1++;
        } else {
            b.push_back({p2, i});
            p2++;
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        ans2 += abs(b[i].second - i);
    }
    ans2 >>= 1;
    //cout << ans1 << " " << ans2 << "\n";
    cout << min(ans1, ans2) << "\n";
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