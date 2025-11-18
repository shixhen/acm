#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i: a) cin >> i;
    long long sum1 = 0, sum2 = 0;
    int cnt = 0;
    long long maxn = -1;
    for (int i = 0; i < n; i++) {
        maxn = max(maxn, a[i]);
        if (a[i] % 2) {
            sum1 += a[i];
            cnt++;
        } else {
            sum2 += a[i];
        }
    }
    if (sum1 == 0 || sum2 == 0) {
        cout << maxn << '\n';
    } else {
        cout << sum1 + sum2 - cnt + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}