#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9;
long long qpow(long long a, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1) {
            res *= a;
            res %= mod;
        }
        t >>= 1;
        a *= a;
        a %= mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    int k;
    cin >> n >> k;
    if (n < k) {
        cout << 1;
    } else {
        cout << qpow(k, n - k);
    }
    return 0;
}