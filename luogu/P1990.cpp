#include <bits/stdc++.h>

using namespace std;

const int mod = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> f(n + 2);
    vector<int> g(n + 2);
    f[0] = 1;
    g[1] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= mod;
        f[i] += g[i - 2] * 2;
        f[i] %= mod;
        g[i] = g[i - 1] + f[i - 1];
        g[i] %= mod;
    }
    cout << f[n];
}