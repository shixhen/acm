#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int a, b, x, y;
    while (t--) {
        cin >> a >> b >> x >> y;
        if (b < a && (a ^ 1) != b) {
            cout << -1 << "\n";
            continue;
        } else if (b < a && (a ^ 1) == b) {
            cout << y << "\n";
            continue;
        }
        long long ans = 0;
        while (a != b) {
            if ((a & 1) == 0 && y < x) {
                ans += y;
                a ^= 1;
            } else {
                a += 1;
                ans += x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}