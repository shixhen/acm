#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (b <= a) cout << a * n << '\n';
        else if (b - a >= n) {
            cout << (b - n + 1 + b) * n / 2 << '\n';
        } else {
            long long cnt = b - a + 1;
            cout << (a + b) * cnt / 2 + a * (n - cnt) << '\n';
        }
    }
    return 0;
}