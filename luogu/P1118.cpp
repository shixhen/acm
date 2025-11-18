#include <bits/stdc++.h>

using namespace std;

int n, sum;
int vis[25] = {0};
int ans[25];
int c[13][13];

void dfs(int dep, int v) {
    if (v > sum) return;
    if (dep > n) {
        if (v == sum) {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << " \n"[i == n];
            }
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            vis[i] = true;
            ans[dep] = i;
            dfs(dep + 1, v + i * c[n][dep]);
            vis[i] = false;
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> sum;
    c[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            //cout << i << ' ' << j << ' ' << c[i][j] << '\n';
        }
    }
    dfs(1, 0);
    return 0;
}