#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 19260817;
long long a, b;

long long read() {
    string s;
    cin >> s;
    long long res = 0;
    for (auto &ch : s) {
        res = (res * 10 + (ch - '0')) % mod;
    }
    return res;
}

long long qpow(long long a, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        t >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a = read();
    b = read();
    if (b == 0) {
        cout << "Angry!" << "\n";
        return 0;
    }
    cout << a * qpow(b, mod - 2) % mod << "\n";

    return 0;
}