#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, long long> mp;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]]--;
        for (int j = 0; j <= 30; j++) {
            if (mp.count((1 << j) - a[i]))
                ans += mp[(1 << j) - a[i]];
        }
    }
    cout << ans << '\n';
    return 0;
}