#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n);
    for (auto &i : a) cin >> i;
    vector<int> b(n);
    auto nxt = [&] (int x) {
        return (x + 1) % n;
    };
    auto pre = [&] (int x) {
        return (x - 1 + n) % n;
    };
    long long ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        d[i] = a[i] - a[pre(i)];
        if (d[i] == 0) cnt++;
        d[i] = abs(d[i]);
        if (d[i] == 0) d[i] = 1e12;
    }
    if (cnt >= n / 2) {
        cout << "0\n";
        return;
    }
    sort(d.begin(), d.end());
    cnt = n / 2 - cnt;
    for (int i = 0; i < cnt; i++) {
        ans += d[i];
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