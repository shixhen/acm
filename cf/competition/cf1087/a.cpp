#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, c, k;
    cin >> n >> c >> k;
    vector<long long> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] > c) {
            break;
        }
        long long t = min(c - a[i], k);
        c += a[i] + t;
        k -= t;
    }
    cout << c << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}