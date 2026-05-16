#include <bits/stdc++.h>
using namespace std;

long long ans[14];
int n;
int full;

void dfs(int col, int ld, int rd) {
    if (col == full) {
        ans[n]++;
        return;
    }

    int pos = full & ~(col | ld | rd);

    while (pos) {
        int p = pos & -pos;
        pos -= p;

        dfs(col | p, (ld | p) << 1, (rd | p) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (n = 1; n <= 13; n++) {
        full = (1 << n) - 1;
        ans[n] = 0;
        dfs(0, 0, 0);
    }

    int x;
    while (cin >> x) {
        cout << ans[x] << '\n';
    }

    return 0;
}