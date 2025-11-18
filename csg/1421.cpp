#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            a[i] = max(a[i], a[i - 1] + a[i]);
            ans = max(ans, a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}