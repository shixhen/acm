#include <bits/stdc++.h>

using namespace std;

long long p;
long long qpow(long long a, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1) {
            res *= a;
            res %= p;
        }
        a *= a;
        a %= p;
        t >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    long long a, b;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << qpow(a, b);
    return 0;
}