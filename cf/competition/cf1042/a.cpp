#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i: a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ans += max(a[i] - b[i], 0);
    }
    cout << ans + 1 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}