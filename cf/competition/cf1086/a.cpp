#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n * n + 1);
    int mx = 0;
    for (int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }
    cout << (mx <= n * n - n ? "YES\n" : "NO\n");

    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}