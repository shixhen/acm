#include <bits/stdc++.h>

using namespace std;

long long qpow(long long a, long long t) {
    if (t <= 0) return 1;
    long long res = 1;
    while (t) {
        if (t & 1) {
            res *= a;
        }
        t >>= 1;
        a *= a;
    }
    return res;
}

long long cost(long long x) {
    return qpow(3, x + 1) + x * qpow(3, x - 1);
}

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    long long ans = 0;
    long long x = 0;
    vector<long long> temp;
    while (n != 0) {
        x = 0;
        while (qpow(3, x) <= n) {
            x++;
        }
        x--;
        k--;
        n -= qpow(3, x);
        ans += cost(x);
        temp.push_back(x);
        if (k == 0 and n != 0) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}