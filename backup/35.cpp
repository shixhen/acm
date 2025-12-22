#include <bits/stdc++.h>

using namespace std;


long long a[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int seed1, seed2, mod, base;
    cin >> seed1 >> seed2 >> mod >> base;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i * seed1 + j * seed2) % mod + base;

        }
    }
    while (m--) {
        int op, x1, y1, x2, y2;
        cin >> op >> x1 >> y1 >> x2 >> y2;
        if (op == 1) {
            long long k;
            cin >> k;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    a[i][j] += k;
                }
            }
        } else {

        }
    }
    return 0;
}