#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << max(a[0], a[1] - a[0]) << "\n";
    return;
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