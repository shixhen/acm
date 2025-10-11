#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<int> f(n + 1);
        for (auto &i : a) {
            cin >> i;
            if (f[i - 1]) {
                f[i] = f[i - 1];
                f[i - 1] = 0;
            } else {
                f[i] = i;
            }
        }
        
        int ans = f[n];
        if (f[n] == 1) {
            ans = 0;
        }
        int add = 0;
        if (a[n - 1] == n and a[0] == 1) {
            add = -2;
        }
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0)
                continue;
            if (f[i] == 1) {
                ans = min(ans, n - i + 1);
            } else {
                ans = min(ans, n - i + f[i] + 1 + add);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}