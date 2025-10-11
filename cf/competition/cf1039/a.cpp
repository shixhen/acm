#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    for (auto &i: a)
        cin >> i;
    sort(a.begin(), a.end(), greater<long long>());
    long long cnt = 0;
    long long ans = n;
    for (int i = 0; i < n; i++) {
        if ((a[i] << cnt) <= c) {
            ans--;
            cnt++;
        }
    }
    cout << ans << "\n";
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