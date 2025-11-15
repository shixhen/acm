#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
long long a[200005];
long long cnt1[200005];
long long cnt3[200005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n + 2; i++) a[i] = cnt1[i] = cnt3[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cnt1[i] += cnt1[i - 1];
        if (a[i] == 1) cnt1[i]++;
    }
    for (int i = n; i >= 1; i--) {
        cnt3[i] += cnt3[i + 1];
        if (a[i] == 3) cnt3[i]++;
    }
    long long ans = 0;
    long long temp = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] == 2) {
            temp += cnt1[i - 1];
            temp %= mod;
            ans += temp * cnt3[i + 1] % mod;
            ans %= mod;
            temp = (temp + temp - cnt1[i - 1]) % mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}