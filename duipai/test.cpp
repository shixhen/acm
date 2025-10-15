#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long x;
    vector<pair<long long, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin() + 1, a.end());
    int r = 0;
    vector<long long> dp(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n && a[i].first == a[i + 1].first) {
            a[i + 1].second = max(a[i + 1].second, a[i].second);
            continue;
        }
        if (a[i].second < r) continue;
        r = a[i].second;
        long long k = ans;
        long long t = ans + 1;
        while (k && k + (a[i].first - 1ll) / dp[k] + 1 - 1 <= ans + 1) {
            t = min(t, k + (a[i].first - 1ll) / dp[k] + 1 - 1);
            if (t == ans) break;
            k--;
        }
        if (t == ans + 1) {
            ans++;
            dp[ans] = a[i].first;
        }
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