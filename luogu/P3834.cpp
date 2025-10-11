#include <bits/stdc++.h>

using namespace std;

constexpr int N = 200005;

int a[N], b[N], sum[N << 5], rt[N << 5], ls[N << 5], rs[N << 5], tot, len;

int f(int val) {
    return lower_bound(b + 1, b + len + 1, val) - b;
}

int build(int l, int r) {
    int root = ++tot;
    if (l == r) return root;
    int mid = (l + r) >> 1;
    ls[root] = build(l, mid);
    rs[root] = build(mid + 1, r);
    return root;
}

int update(int root, int l, int r, int k) {
    int dir = ++tot;
    ls[dir] = ls[root];
    rs[dir] = rs[root];
    sum[dir] = sum[root] + 1;
    if (l == r) return dir;
    int mid = (l + r) >> 1;
    if (k <= mid) {
        ls[dir] = update(ls[dir], l, mid, k);
    } else {
        rs[dir] = update(rs[dir], mid + 1, r, k);
    }
    return dir;
}

int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int x = sum[ls[v]] - sum[ls[u]];
    if (x >= k) {
        return query(ls[u], ls[v], l, mid, k);
    } else {
        return query(rs[u], rs[v], mid + 1, r, k - x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, l, r, k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    rt[0] = build(1, len);
    for (int i = 1; i <= n; i++) {
        rt[i] = update(rt[i - 1], 1, len, f(a[i]));
    }
    while (m--) {
        cin >> l >> r >> k;
        cout << b[query(rt[l - 1], rt[r], 1, len, k)] << "\n";
    }
    return 0;
}