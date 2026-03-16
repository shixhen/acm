#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 30 || (a >= 21 && (a - b) >= 2)) {
        cout << "Alice\n";
        return;
    }
    if (b == 30 || (b >= 21 && (b - a) >= 2)) {
        cout << "Bob\n";
        return;
    }
    cout << "Underway\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}