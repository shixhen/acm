#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> l(n, INT_MAX), r(n, INT_MAX);
    vector<int> cnt(n);
    for (auto &i: a)
        cin >> i;
    int idx;
    for (int i = 0; i < n; i++) {
        idx = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
        l[idx] = a[i];
        cnt[i] += idx + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        idx = lower_bound(r.begin(), r.end(), a[i]) - r.begin();
        r[idx] = a[i];
        cnt[i] += idx + 1;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int cur = n - cnt[i] + 1;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}