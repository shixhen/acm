#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &x : a) cin >> x; 
    int x = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += abs(a[i] - a[i - 1]);
        x = max(x, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
    }
    sum += abs(a[n - 1] - a[n - 2]);
    x = max(x, abs(a[0] - a[1]));
    x = max(x, abs(a[n - 1] - a[n - 2]));

    sum -= x;
    cout << sum << "\n";
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