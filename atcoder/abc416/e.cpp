#include <bits/stdc++.h>

using namespace std;

long long g[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            if (i == j) continue;
            g[i][j] = 0x3f3f3f3f3f;
        }
    }
    long long ai, bi, ci, di;
    for (int i = 1; i <= m; i++) {
        cin >> ai >> bi >> ci;
        g[ai][bi] = min(g[ai][bi], ci);
        g[bi][ai] = g[ai][bi];
    }
    long long k, t;
    vector<int> d(k);
    cin >> k >> t;
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++) {
        g[i][n + 1] = t;
        g[n + 1][i] = 0;
    }
    for (int kk = 1; kk <= n + 1; kk++) {
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                if (i == j) continue;
                g[i][j] = min(g[i][kk] + g[kk][j], g[i][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 0x3f3f3f3f3f || i == j) {
                continue;
            }
            ans += g[i][j];
        }
    }
    int q;
    cin >> q;
    int op, x, y;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> t;
            if (t < g[x][y]) {
                if (g[x][y] != 0x3f3f3f3f3f)
                    ans -= g[x][y] * 2ll;
                g[x][y] = t;
                g[y][x] = g[x][y];
                ans += g[x][y] * 2ll;
                for (int i = 1; i <= n; i++) {
                    if (i == x || i == y) continue;
                    if (g[i][x] > g[i][y] + g[y][x]) {
                        if (g[i][x] != 0x3f3f3f3f3f)
                            ans -= g[i][x] * 2ll;
                        g[i][x] = g[i][y] + g[y][x];
                        g[x][i] = g[i][x];
                        ans += g[i][x] * 2ll;
                        for (int j = 1; j <= n; j++) {
                            if (j == i || j == x) continue;
                            if (g[i][j] != 0x3f3f3f3f3f)
                                ans -= g[i][j] * 2ll;
                            g[i][j] = min(g[i][j], g[i][x] + g[x][j]);
                            g[j][i] = g[i][j];
                            if (g[i][j] != 0x3f3f3f3f3f)
                                ans += g[i][j] * 2ll;
                        }
                    }
                    if (g[i][y] > g[i][x] + g[x][y]) {
                        if (g[i][y] != 0x3f3f3f3f3f)
                            ans -= g[i][y] * 2ll;
                        g[i][y] = g[i][x] + g[x][y];
                        g[y][i] = g[i][y];
                        ans += g[i][y] * 2ll;
                        for (int j = 1; j <= n; j++) {
                            if (j == i || j == y) continue;
                            if (g[i][j] != 0x3f3f3f3f3f)
                                ans -= g[i][j] * 2ll;
                            g[i][j] = min(g[i][j], g[i][y] + g[y][j]);
                            g[j][i] = g[i][j];
                            if (g[i][j] != 0x3f3f3f3f3f)
                                ans += g[i][j] * 2ll;
                        }
                    }
                }
            }
        } else if (op == 2) {
            cin >> x;
            g[x][n + 1] = t;
            g[n + 1][x] = 0;
            
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}