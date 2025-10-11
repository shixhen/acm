#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        ll maxn = 0;
        ll max_idx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > maxn) {
                max_idx = i;
                maxn = a[i];
            }
        }
        if (n <= 2) {
            cout << "0\n";
            continue;
        }
        ll ans = maxn * (n - 3);
        if (max_idx == 0 || max_idx == n - 1) {
            ans += maxn;
        } else {
            ans += max(a[0], a[n - 1]);
        }
        
        cout << ans << "\n";


    }
    return 0;
}