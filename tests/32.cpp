#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

struct Node {
    int l;
    int r;
    int len;

    long long val;
    long long lazy;

    bool full_cover(int s, int t) {
        return s <= l && r <= t;
    }

} seg[N << 2];

void build(int p, int l, int r) {
    seg[p].l = l;
    seg[p].r = r;
    seg[p].len = r - l + 1;
    seg[p].lazy = 0;
    if (l == r) {
        cin >> seg[p].val;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    seg[p].val = seg[p << 1].val + seg[p << 1 | 1].val;
}

void push_down(int p) {
    if (seg[p].lazy == 0) return;
    seg[p << 1].val += seg[p].lazy * seg[p << 1].len;
    seg[p << 1 | 1].val += seg[p].lazy * seg[p << 1 | 1].len;
    seg[p << 1].lazy += seg[p].lazy;
    seg[p << 1 | 1].lazy += seg[p].lazy;
    seg[p].lazy = 0;
}

void update(int p, int s, int t, long long v) {
    if (seg[p].full_cover(s, t)) {
        seg[p].val += v * seg[p].len;
        seg[p].lazy += v;
        return;
    }
    push_down(p);
    int mid = (seg[p].l + seg[p].r) >> 1;
    if (s <= mid) {
        update(p << 1, s, t, v);
    }
    if (t > mid) {
        update(p << 1 | 1, s, t, v);
    }
    seg[p].val = seg[p << 1].val + seg[p << 1 | 1].val;
}

long long query(int p, int s, int t) {
    if (seg[p].full_cover(s, t)) {
        return seg[p].val;
    }
    push_down(p);
    int mid = (seg[p].l + seg[p].r) >> 1;
    long long res = 0;
    if (s <= mid) {
        res += query(p << 1, s, t);
    }
    if (t > mid) {
        res += query(p << 1 | 1, s, t);
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    int op, x, y;
    long long k;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(1, x, y, k);
        } else if (op == 2) {
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
    }
    return 0;
}