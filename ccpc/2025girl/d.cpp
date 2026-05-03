#include <bits/stdc++.h>

using namespace std;


constexpr int N = (1 << 22);

int f[N];
int w[23][N];
int c[23];

int a[23][23];
int b[23][23];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        cin >> a[u][v] >> b[u][v];
    }
    for (int i = 1; i < (1 << 22); i++) {
        f[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < (1 << n); j++) {
            if ((j >> (i - 1)) & 1) {
                continue;
            }
            int u = 32 - __builtin_clz(j);
            w[i][j] = w[i][j ^ (1 << (u - 1))] + min(a[i][u], b[i][u]);
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            if ((i >> (j - 1)) & 1) {
                f[i] = min(f[i], f[i ^ (1 << (j - 1))] + w[j][i ^ (1 << (j - 1))]);
            }
        }
    }
    long long ans = 1e18;
    for (int i = 0; i < (1 << n); i++) {
        long long cost = 0;
        for (int j = 1; j <= n; j++) {
            if (!((i >> (j - 1)) & 1)) {
                cost += c[j];
            }
        }
        //cout << cost << " " << f[i] << "\n";
        ans = min(ans, cost + f[i]);
    }
    cout << ans << "\n";
    return 0;
}