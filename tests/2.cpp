#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

long long a[300005] = {0};

long long t[300005] = {0};
const long long mod = 998244353;

long long qui(int a, int k, int p) {
    int res = 1;
    while(k > 0){
        res = a * res % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= (n + 1) / 2; i++) {
        t[i] = ((a[n - i + 1] - a[i - 1]) % mod) % mod;
        t[i] = (t[i] + t[i - 1]) % mod;
    }
    long long ans = 0;
    for (int len = 1; len <= n; len++) {
        ans = ans + (t[min(len, n - len + 1)]) % mod;
        ans %= mod;
    }
    long long p = mod;
    qui(ans, p, mod);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)solve();
    long long a = 0x7f7f7f7f7f7f7f7f;
    return 0;
}