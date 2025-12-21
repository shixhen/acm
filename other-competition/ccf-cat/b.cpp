#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, num = 0;
    cin >> a >> b;
    while (a >= 10) {
        num += a % 10;
        a /= 10;
    }
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