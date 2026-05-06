#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long p, a, b, q, c, d, m, t;
    cin >> p >> a >> b >> q >> c >> d >> m >> t;
    
    if (m < p) {
        cout << m << "\n";
        return;
    }
    long long ans = m;
    while (t > 0) {
        long long k = ((p - ans % p) - 1) / ((q - p) * (ans / p)) + 1;
        if (k * (b + d) + k * (ans / p) * (a + c) > t) {
            break;
        }
        t -= k * (b + d) + k * (ans / p) * (a + c);
        ans += k * (q - p) * (ans / p);
    }
    
    long long k = t / ((b + d) + (ans / p) * (a + c));
    t -= k * ((b + d) + (ans / p) * (a + c));
    ans += k * (q - p) * (ans / p);;
    
    ans += max(0ll, (t - b - d) / (a + c) * (q - p));
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}