#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 2 || n == 4) {
        cout << "-1\n";
        return;
    }
    int a = n / 3;
    int b = n % 3;
    if (b == 0) {
        cout << a << "\n";
    } else if (b == 1) {
        cout << a - 1 << "\n";
    } else if (b == 2) {
        cout << a << "\n";
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}