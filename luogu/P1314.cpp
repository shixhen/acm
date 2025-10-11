#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, m, s;
    cin >> n >> m >> s;
    vector<long long> w(n + 1);
    vector<long long> v(n + 1);
    vector<pair<int, int>> a(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    long long ans = 0x3f3f3f3f3f3f3f3f;
    auto check = [&](int k) {
        vector<int> temp((int) n + 1);
        vector<long long> sum((int) n + 1);
        for (int i = 1; i <= n; i++) {
            temp[i] = temp[i - 1];
            sum[i] = sum[i - 1];
            if (w[i] >= k) {
                sum[i] += v[i];
                temp[i]++;
            }        
        }
        long long res = 0;
        for (int i = 1; i <= m; i++) {
            res +=(long long) (sum[a[i].second] - sum[a[i].first - 1]) * (temp[a[i].second] - temp[a[i].first - 1]);
        }
        ans = min(ans, abs(res - s));
        //cout << res << "   " << k << '\n';
        return res >= s;
    };
    int l = 0, r = 1e6 + 5;
    int mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    check(r - 1);
    cout << ans;
}