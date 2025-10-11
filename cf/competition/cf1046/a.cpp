#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > (a + 1) * 2 || a > (b + 1) * 2) {
        cout << "No\n";
        return;
    }
    a = c - a;
    b = d - b;
    if (b > (a + 1) * 2 || a > (b + 1) * 2) {
        cout << "No\n";
        return;
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
