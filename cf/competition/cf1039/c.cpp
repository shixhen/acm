#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &i: b)
        cin >> i;
    int x;
    int minb = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i] > minb) {
            x = b[i] / 2;
            if (x * 2 == b[i])
                x--;
            if (x >= minb || x + minb < b[i]) {
                cout << "No\n";
                return;
            }
        }
        minb = min(minb, b[i]);
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