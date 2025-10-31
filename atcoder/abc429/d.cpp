#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, m, c;
    cin >> n >> m >> c;
    map<long long, long long> mp;
    long long maxn = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        mp[x]++;
        maxn = max(maxn, x);
        mp[x + m]++;
    }
    //cout << 111 << endl;
    vector<pair<long long, long long>> a;
    a.push_back({maxn - m, 0});
    for (auto &p : mp) {
        a.push_back({p.first, p.second});
    }
    //cout << 111 << endl;
    int r = 0;
    long long l = 1;
    long long sum = 0;
    long long ans = 0;
    while (1) {
        while (sum < c && r + 1 < (int)a.size()) {
            r++;
            sum += a[r].second;
        }
        ans += sum * (a[l].first - a[l - 1].first);
        //cout << l << " " << r << " " << a[l].first << " " << sum << " " << ans << "\n";
        sum -= a[l].second;
        l++;
        if (a[l].first >= m) break;
    }
    cout << ans << "\n";
    return 0;
}