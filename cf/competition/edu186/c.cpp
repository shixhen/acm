#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    long long cnt1 = 0, cnt2 = 0;
    for (int be = 0; be < n; be++) {
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[(be + i) % n]) {
                f = false;
                break;
            }
        }
        if (f) {
            cnt1++;
        }
    }
    for (int be = 0; be < n; be++) {
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (b[i] >= c[(be + i) % n]) {
                f = false;
                break;
            }
        }
        if (f) {
            cnt2++;
        }
    }
    cout << cnt1 * cnt2 * n << "\n";
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