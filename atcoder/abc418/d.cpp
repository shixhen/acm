#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp1[200005];
ll dp0[200005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string t;
    cin >> n >> t;
    t = " " + t;
    if (t[1] == '0') {
        dp0[1]++;
    } else {
        dp1[1]++;
    }
    for (int i = 2; i <= n; i++) {
        if (t[i] == '0') {
            dp1[i] = dp0[i - 1];
            dp0[i] = dp1[i - 1] + 1;
        } else {
            dp1[i] = dp1[i - 1] + 1;
            dp0[i] = dp0[i - 1];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp1[i];
    }
    cout << ans;
    return 0;
}