#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] = i * 2 - a[i];
    }
    long long t = 0;
    long long maxn = 0;
    for (int i = 1; i <= n; i++) {
        if (t < 0) {
            t = 0;
        }
        t += a[i];
        maxn = max(maxn, t);
    }
    cout << sum + maxn << "\n";
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
