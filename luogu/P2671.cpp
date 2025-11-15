#include <bits/stdc++.h>

using namespace std;
const long long mod = 10007;
array<long long, 4> a[100005][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> num(n + 1);
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            a[c[i]][1][0] += i;
            a[c[i]][1][1] += num[i];
            a[c[i]][1][2] += num[i] * i;
            a[c[i]][1][3]++;
        } else {
            a[c[i]][0][0] += i;
            a[c[i]][0][1] += num[i];
            a[c[i]][0][2] += num[i] * i;
            a[c[i]][0][3]++;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        if (a[i][1][3] >= 2) {
            ans += (a[i][1][0] % mod) * (a[i][1][1] % mod) + ((a[i][1][2] % mod) * (a[i][1][3] - 2) % mod);
            ans %= mod;
        }
        if (a[i][0][3] >= 2) {
            ans += (a[i][0][0] % mod) * (a[i][0][1] % mod) + ((a[i][0][2] % mod) * (a[i][0][3] - 2) % mod);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}