#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long maxn = 0;
    for (auto &i: a) {
        cin >> i; 
    }
    for (int i = 1; i < n - 1; i++) {
        maxn = max(maxn, a[i]);
    }
    if (k == 1) {
        cout << max(a[0] + a[n - 1], maxn + max(a[0], a[n - 1])) << '\n';
    } else {
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = a.size() - 1; i >= n - k - 1; i--) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}