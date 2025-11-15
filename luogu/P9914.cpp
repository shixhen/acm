#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    unordered_map<long long, int> mp;
    int n, m;
    cin >> n >> m;
    long long x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x != 0)
            mp[x * i]++;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (x != 0 && mp.count(x * i))
            ans += mp[x * i];
    }
    cout << ans;
    return 0;
}