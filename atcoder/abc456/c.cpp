#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    s += s.back();
    int n = s.size();
    long long l = 0;
    // cout << s << endl;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            long long len = i - l + 1;
            ans += (long long) len * (len + 1ll) / 2ll;
            ans %= 998244353ll;
            l = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}