#include <bits/stdc++.h>

using ll = long long;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 0) {
            cout << "0\n";
            continue;
        }
        if (n % 2) {
            cout << n << "/" << ((n + 1ll) << 1) << "\n";
        } else {
            cout << n / 2 << "/" << n + 1ll << "\n";
        }
        
    }

    return 0;
}