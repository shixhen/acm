#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int _;
    for (int i = 1; i <= n; i++) {
        cin >> _;
        sum += _;
    }
    if (sum % x == 0 && sum / x == n) cout << "YES\n";
    else cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}