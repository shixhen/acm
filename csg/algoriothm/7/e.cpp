#include <bits/stdc++.h>

using namespace std;

int g[20][20];
int c[20][20];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    int u, v;
    for (int i = 1; i <= q; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
}