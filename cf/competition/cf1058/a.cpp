#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.insert(a[i]);
    }
    int ans = 0;
    while (b.count(ans)) ans++;
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