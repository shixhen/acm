#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] == 1 && i != 1) {
            ans = 1;
        } else {
            ans = min(n - a[i] + 1, ans);
        }
    }
    cout << ans << "\n";

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