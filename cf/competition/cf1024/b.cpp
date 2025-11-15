#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[i]) < abs(a[0])) cnt++;
    }
    if (cnt <= n / 2) cout << "Yes\n";
    else cout << "No\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}