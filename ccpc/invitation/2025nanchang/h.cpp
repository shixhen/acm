#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> b(n + 2);
    b[n + 1] = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] < i) {
            cout << "-1\n";
            return;
        }
        b[i] = min(b[i + 1] - 1, a[i]);
    }
    long long ans = 0;
    long long se = 1;
    long long r = 0;
    for (int i = 1; i <= n; i++) {
        long long t = min(b[i] - se, r);
        ans += t;
        r -= t;
        se += t;
        ans++;
        r += a[i] - se; 
        se++;
        //cout << i << " " << ans << " " << r << " " << se << "\n";
    }
    ans += r;
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}