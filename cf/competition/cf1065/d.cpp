#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        maxn = max(maxn, n - a[i] + 1);
        if (maxn <= i) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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