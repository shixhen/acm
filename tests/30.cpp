#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a = 2;
    int b = 3;
    long long c = qpow(a, mod - 2);
    cout << c << "\n";
    cout << (c * b) % mod << "\n";
    return 0;
}