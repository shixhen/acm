#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    long long l = 0, r = 0;
    long long t1, t2;
    for (int i = 0; i < n; i++) {
        t1 = min(l - a[i], b[i] - r);
        t2 = max(r - a[i], b[i] - l);
        l = t1;
        r = t2;
    }
    cout << r << "\n";
    return;
}


int main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}