#include <bits/stdc++.h>

using namespace std;

int g[105][105];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    memset(g, 0x3f3f3f3f, sizeof(g));
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int u, v, w;
    for (int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        a[i] = w;
        g[i][i] = 0;
        if (v > 0) g[i][v] = g[v][i] = 1;
        if (u > 0) g[i][u] = g[u][i] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
            }
        }
    }
    int ans = 0x7fffffff;
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = 0;
        for (int j = 1; j <= n; j++) {
            temp += g[i][j] * a[j];
        }
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}