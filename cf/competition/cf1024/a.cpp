#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p) {
        cout << "Yes\n";
    } else {
        if (n / p * q == m) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
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