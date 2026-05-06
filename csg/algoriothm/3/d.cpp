#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1.0);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd& x : a) x /= n;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) res[i] = (int)round(fa[i].real());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string sa, sb;
    cin >> sa >> sb;
    
    if (sa == "0" || sb == "0") {
        cout << "0\n";
        return 0;
    }
    
    vector<int> a(sa.size()), b(sb.size());
    for (size_t i = 0; i < sa.size(); ++i) a[sa.size() - 1 - i] = sa[i] - '0';
    for (size_t i = 0; i < sb.size(); ++i) b[sb.size() - 1 - i] = sb[i] - '0';
    
    auto res = multiply(a, b);
    
    int carry = 0;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    
    for (int i = (int)res.size() - 1; i >= 0; --i) cout << res[i];
    cout << '\n';
    return 0;
}