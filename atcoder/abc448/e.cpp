#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 qpow(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    i64 n, m;
    i64 mod = 10007;
    cin >> n >> m;
    i64 p = mod * m;
    i64 x = 0, y = 0; // y未使用

    while (n--) {
        int c, l;
        cin >> c >> l;
        x = (x * qpow(10, l, p) + c * (qpow(10, l, 9 * p) - 1) % (9 * p) / 9) % p;
    }
    cout << (x - x % m) % mod * qpow(m, mod - 2, mod) % mod << endl;
}