#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, n;
    cin >> a >> b >> n;
    if (b >= a) {
        cout << "1\n";
        return;
    }
    long long t = a / b;
    if (n <= t) {
        cout << "1\n";
        return;
    }
    cout << 2 << "\n";
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