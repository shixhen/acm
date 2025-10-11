#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    long long ans = 0;
    sort(a.begin(), a.end(), [] (int x, int y) { return x >= y;});
    sort(b.begin(), b.end(), [] (int x, int y) { return x >= y;});
    int i;
    for (i = 0; i < m; i++) {
        if (b[i] <= 0) break;
        if (b[i] + a[i] <= 0) {
            cout << ans;
            return 0;
        }
        ans += b[i] + a[i];
        if (i == n - 1) {
            cout << ans;
            return 0;
        }
    }
    for (int j = i; j < n; j++) {
        if (a[j] <= 0) {
            cout << ans;
            return 0;
        } else {
            ans += a[j];
        }
    }
    cout << ans;
    return 0;
}