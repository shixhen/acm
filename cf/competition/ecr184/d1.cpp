#include <bits/stdc++.h>

using namespace std;
constexpr long long N = 1000000000000ll;

void solve() {
    long long x, y, k;
    cin >> x >> y >> k;
    if (y == 1) {
        cout << "-1\n";
        return;
    }
    if (k == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= x; i++) {
        k = k + (k - 1ll) / (y - 1ll);
        if (k > N) {
            cout << "-1\n";
            return;
        }
    }
    cout << k << "\n";
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
