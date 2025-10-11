#include <bits/stdc++.h>

using namespace std;

constexpr int pp = 131;

long long ans = 0;

int n;
vector<long long> f, g, p;

void bin_s(int x) {
    int l = 0, r = min(x, n - x), mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (f[x] - f[x - mid] * p[mid] == g[x + 1] - g[x + mid + 1] * p[mid]) l = mid;
        else r = mid - 1;
    }
    ans += l;
}
  
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    string s;
    cin >> s;
    f.resize(s.size() + 5);
    g.resize(s.size() + 5);
    p.resize(s.size() + 5);
    string t = " " + s + " ";
    s = t;
    for (int i = 1; i <= n; i++) {
        t[i] = '1' + '0' - t[i];
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * pp;
        f[i] = f[i - 1] * pp + s[i];
    }
    for (int i = n; i >= 1; i--) {
        g[i] = g[i + 1] * pp + t[i];
    }
    for (int i = 1; i <= n; i++) {
        bin_s(i);
    }
    cout << ans;
    return 0;
}