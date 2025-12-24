#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXM = 50000;

ll fact[MAXM + 5];
ll invFact[MAXM + 5];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXM + 2; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    ll x;
    cin >> x;
    if (x <= 2) {
        cout << x << endl;
        return;
    }

    ll l = 2, r = MAXM, m = 2;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if ((mid + 2) * (mid - 1) / 2 <= x) {
            m = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    ll sum = (m + 2) * (m - 1) / 2;
    ll rem = x - sum;
    ll ans;

    if (rem == m) {
        ans = (fact[m] * modInverse(2)) % MOD;
        ans = (ans * (m + 2)) % MOD;
    } else {
        ans = fact[m];
        ll removed = m - rem + 1;
        ans = (ans * modInverse(removed)) % MOD;
        ans = (ans * (m + 1)) % MOD;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}