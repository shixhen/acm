#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2) {
            cout << l << "\n";
        } else {
            if (n == 2) {
                cout << -1 << "\n";
                continue;
            }
            int cnt = 1;
            long long temp = l;
            while (temp != 1) {
                temp >>= 1;
                cnt++;
            }
            temp <<= cnt;
            if (temp > r) {
                cout << -1 << "\n";
            } else {
                if (k != n - 1 && k != n) {
                    cout << l << "\n";
                } else {
                    cout << temp << "\n";
                }
            }
        }
    }
    return 0;
}