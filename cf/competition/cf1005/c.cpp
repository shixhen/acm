#include <bits/stdc++.h>

using namespace std;
int dp[200005][3];
int a[200005];
int p[200005];
void solve() {
    int n;
    cin >> n;
    long long fsum = 0;
    long long psum = 0;
    for (int i = 1; i<= n; i++) {
        p[i] = 0;
        cin >> a[i];
        if (a[i] < 0) fsum -= a[i];
    }
    long long ans = fsum;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            psum += a[i];
            ans = max(psum + fsum, ans);
        } else {
            fsum += a[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}