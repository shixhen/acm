#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

constexpr ll N = 2e6 + 5;

// 动态开点
int ls[N << 2], rs[N << 2], cnt, root;
ll node[N << 2], lazy[N << 2];

void pushdown(int p, int s, int t) {
    if (lazy[p]) {
        int mid = (s + t) >> 1;
        if (!ls[p]) ls[p] = ++cnt;
        if (!rs[p]) rs[p] = ++cnt;
        lazy[ls[p]] += lazy[p];
        lazy[rs[p]] += lazy[p];
        node[ls[p]] += lazy[p] * (mid - s + 1);
        node[rs[p]] += lazy[p] * (t - mid);
        lazy[p] = 0;
    }
}

void add(int &p, int s, int t, int x, ll v) {
    if (!p) p = ++cnt;
    if (s == t) {
        node[p] += v;
        return;
    }
    pushdown(p, s, t);
    int mid = (s + t) >> 1;
    if (x <= mid)
        add(ls[p], s, mid, x, v);
    else
        add(rs[p], mid + 1, t, x, v);
    node[p] = node[ls[p]] + node[rs[p]];
}

// 区间加
void update(int &p, int s, int t, int l, int r, ll v) {
    if (!p) p = ++cnt;
    if (l <= s && t <= r) {
        node[p] += (ll) v * (t - s + 1);
        lazy[p] += v;
        return;
    }
    pushdown(p, s, t);
    int mid = (s + t) >> 1;
    if (l <= mid) {
        update(ls[p], s, mid, l, r, v);
    }
    if (r > mid) {
        update(rs[p], mid + 1, t, l, r, v);
    }
    node[p] = node[ls[p]] + node[rs[p]];
}

ll query(int p, int s, int t, int l, int r) {
    if (!p) return 0;
    if (s >= l && t <= r) {
        return node[p];
    }
    pushdown(p, s, t);
    int mid = (s + t) >> 1;
    ll res = 0;
    if (l <= mid) {
        res += query(ls[p], s, mid, l, r);
    }
    if (r > mid) {
        res += query(rs[p], mid + 1, t, l, r);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m, op, x, y, k;
    cin >> n >> m;
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            update(root, 1, n, x, y, k);
        } else {
            cout << query(root, 1, n, x, y) + ((x + y) * (y - x + 1ll) / 2ll) << "\n";
        }
    }
    return 0;
}