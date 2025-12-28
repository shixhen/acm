#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

struct Node {
    int l;
    int r;
    int mid;
    int len;

    int ls;
    int rs;

    long long val;
    long long lazy;

    bool in_range(int s, int t) {
        return s <= l && r <= t;
    }
} seg[N << 2];

int n, tot, root;

void enable(int &x, int l, int r) {
    if (x == 0) {
        x = ++tot;
        seg[x].l = l;
        seg[x].r = r;
        seg[x].mid = (l + r) >> 1;
        seg[x].len = r - l + 1;
    }
    return;
}

void push_down(int p) {
    if (seg[p].lazy == 0) return;
    enable(seg[p].ls, seg[p].l, seg[p].mid);
    enable(seg[p].rs, seg[p].mid + 1, seg[p].r);
    for (auto &child : {seg[p].ls, seg[p].rs}) {
        seg[child].val += seg[p].lazy * seg[child].len;
        seg[child].lazy += seg[p].lazy;
    }

    seg[p].lazy = 0;
}

void update(int p, int s, int t, const long long v) {
    if (seg[p].in_range(s, t)) {
        seg[p].val += v * seg[p].len;
        seg[p].lazy += v;
        return;
    }
    push_down(p);
    if (s <= seg[p].mid) {
        enable(seg[p].ls, seg[p].l, seg[p].mid);
        update(seg[p].ls, s, t, v);
    }
    if (t > seg[p].mid) {
        enable(seg[p].rs, seg[p].mid + 1, seg[p].r);
        update(seg[p].rs, s, t, v);
    }
    seg[p].val = seg[seg[p].ls].val + seg[seg[p].rs].val;
}

long long query(int p, int s, int t) {
    if (!p) return 0;
    if (seg[p].in_range(s, t)) {
        return seg[p].val;
    }
    push_down(p);
    long long res = 0;
    if (s <= seg[p].mid) {
        res += query(seg[p].ls, s, t);
    }
    if (t > seg[p].mid) {
        res += query(seg[p].rs, s, t);
    }
    return res;
}

void update(long long v) {
    update(root, 1, n, v);
}

long long query(int s, int t) {
    return query(root, s, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    enable(root, 1, n);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        update(root, i, i, x);
    }
    int op, x, y;
    long long k;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(root, x, y, k);
        } else if (op == 2) {
            cin >> x >> y;
            cout << query(root, x, y) << "\n";
        }
    }
    return 0;
}