#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k, m;
    cin >> n >> k >> m;
    long long t = n / k;
    long long a = t - max(0ll, (m - (n - t)));
    cout << (a + 1ll) / 2ll + m << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}