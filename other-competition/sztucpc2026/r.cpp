#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;

int idx[N];
int sz[N];
int f[N];

int tot;
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    f[y] = x;
    sz[x] += sz[y];
}

void spilt(int x) {
    tot++;
    sz[find(idx[x])]--;
    idx[x] = tot;
    f[tot] = tot;
    sz[tot] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    tot = n;
    for (int i = 1; i <= n; i++) {
        idx[i] = i;
        f[i] = i;
        sz[i] = 1;
    }
    int op, x, y;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            merge(idx[x], idx[y]);
        } else if (op == 2) {
            cin >> x;
            spilt(x);
        } else if (op == 3) {
            cin >> x >> y;
            cout << (find(idx[x]) == find(idx[y]) ? "Yes" : "No") << "\n";
        } else { 
            cin >> x;
            cout << sz[find(idx[x])] << "\n";
        }
    }
    return 0;
}