#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<long long> d(n + 2);
    for (auto &i: a) {
        cin >> i;
        if (i == n) i--;
        d[n - i]++;
    }
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    long long ans = 0;
    for (auto &i: a) {
        ans += (long long) d[i];
        if (i >= n - i) ans -= ((long long) 2 * i - n + (long long) 1);
    }
    cout << ans << '\n';
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