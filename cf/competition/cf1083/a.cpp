#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == n) {
            swap(a[i], a[0]);
            break;
        }
    }
    for (auto x : a) {
        cout << x << " ";
    }
    cout << "\n";
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