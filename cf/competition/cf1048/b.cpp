#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    if (m <= n) {
        long long j = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += a[i] * (m - j);
            if (m - j == 0) break;
            j++;
            
        }
        cout << ans << "\n";
        return;
    }
    ans += (m - n + 1) * a[0];
    for (int i = 1; i < n; i++) {
        ans += a[i] * (m - n + 1 + i);
    }
    cout << ans << "\n";


    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}