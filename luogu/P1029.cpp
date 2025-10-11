#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 1 << "\n";
        return 0;
    }
    long long ans = 0;
    for (long long i = x; i * i <= y * x; i++) {
        if (y % i == 0 and i % x == 0 and __gcd(i, x * y / i) == x) {
            ans += 2;
        }
    }
    cout << ans << "\n";
    return 0;
}