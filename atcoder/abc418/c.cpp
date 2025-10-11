#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ans[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, q, x, maxn = 0;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> num(n);
    
    for (auto &i: a) {
        cin >> i;
        maxn = max(maxn, i);
    }
    sort(a.begin(), a.end());
    ans[1] = 1;
    ll p = 0;
    ll sum = 0;
    for (int i = 2; i <= 1000001; i++) {
        while (p < n and a[p] < i) {
            sum += a[p++];
        }
        ans[i] = sum + (n - p) * (i - 1) + 1;;;
    }
    while (q--) {
        cin >> x;
        if (x > maxn) {
            cout << "-1\n";
            continue;
        }
        if (x == 1) {
            cout << "1\n";
            continue;
        }
        cout << ans[x] << "\n";

    }
    return 0;
}