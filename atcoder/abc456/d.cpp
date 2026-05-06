#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long l = 0;
    // cout << s << endl;
    long long ans = 0;
    long long cnta = 0;
    long long cntb = 0;
    long long cntc = 0;
    if (s[0] == 'a') {
        cnta++;
    } else if (s[0] == 'b') {
        cntb++;
    } else {
        cntc++;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'a') {
            cnta++;
            cnta += cntb;
            cnta += cntc;
            cnta %= mod;
        } else if (s[i] == 'b') {
            cntb++;
            cntb += cnta;
            cntb += cntc;
            cntb %= mod;
        } else {
            cntc++;
            cntc += cnta;
            cntc += cntb;
            cntc %= mod;
        }
    }
    cout << (cnta + cntb + cntc) % mod << endl;
    return 0;
}