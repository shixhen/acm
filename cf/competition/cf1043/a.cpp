#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string b;
    int m;
    string c;
    cin >> n >> b >> m >> c;
    string vd;
    cin >> vd;
    for (int i = 0; i < m; i++) {
        if (vd[i] == 'D') {
            b += c[i];
        } else {
            b = c[i] + b;
        }
    }
    cout << b << "\n";
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