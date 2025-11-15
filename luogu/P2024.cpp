#include <bits/stdc++.h>

using namespace std;

vector<int> f;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        f[x] = y;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    f.resize(3 * n + 1);
    iota(f.begin(), f.end(), 0);
    int cnt = 0;
    int x, y, op;
    while (k--) {
        cin >> op >> x >> y;
        if (x > n || y > n || (op == 2 && x == y)) {
            cnt++;
            continue;
        }
        if (op == 1) {
            if (find(x) == find(y + n) || find(x + n) == find(y)) {
                cnt++;
            } else {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + 2 * n, y + 2 * n);
            }
        } else {
            if (find(x) == find(y) || find(x + n) == find(y)) {
                cnt++;
            } else {
                merge(x, y + n);
                merge(x + n, y + 2 * n);
                merge(x + 2 * n, y);
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}