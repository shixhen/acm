#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;
constexpr int add(int a, int b) {
    return a + b;
}
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
    cout << add(3, 5) << "\n";
    return 0;
}