#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> b(n);
    b[0] = a[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1] + 1 && a[i] >= b[i - 1] + 1) {
            b[i] = b[i - 1];
        } else {
            b[i] = a[i];
            ans++;
        }
    }
    cout << ans << "\n";
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