#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

struct Node {
    int l;
    int r;
    int len;

    long long val;

    long long maxn;
    long long hmax;

    long long lazy;
    long long hlazy;

    bool full_cover(int s, int t) {
        return s <= l && r <= t;
    }

} seg[N << 2];

void build(int p, int l, int r) {
    seg[p].l = l;
    seg[p].r = r;
    seg[p].len = r - l + 1;
    seg[p].lazy = 0;
    seg[p].hlazy = 0;
    if (l == r) {
        cin >> seg[p].val;
        seg[p].maxn = seg[p].val;
        seg[p].hmax = seg[p].val;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    seg[p].val = seg[p << 1].val + seg[p << 1 | 1].val;
    seg[p].maxn = max(seg[p << 1].maxn, seg[p << 1 | 1].maxn);
    seg[p].hmax = seg[p].maxn;
}

void push_down(int p) {
    if (seg[p].lazy == 0 && seg[p].hlazy == 0) return;

    seg[p << 1].val += seg[p].lazy * seg[p << 1].len;
    seg[p << 1 | 1].val += seg[p].lazy * seg[p << 1 | 1].len;

    seg[p << 1].hmax = max(seg[p << 1].hmax, seg[p << 1].maxn + seg[p].hlazy);
    seg[p << 1 | 1].hmax = max(seg[p << 1 | 1].hmax, seg[p << 1 | 1].maxn + seg[p].hlazy);

    seg[p << 1].maxn += seg[p].lazy;
    seg[p << 1 | 1].maxn += seg[p].lazy;

    seg[p << 1].hlazy = max(seg[p << 1].hlazy, seg[p << 1].lazy + seg[p].hlazy);
    seg[p << 1 | 1].hlazy = max(seg[p << 1 | 1].hlazy, seg[p << 1 | 1].lazy + seg[p].hlazy);
    
    seg[p << 1].lazy += seg[p].lazy;
    seg[p << 1 | 1].lazy += seg[p].lazy;

    seg[p].hlazy = 0;
    seg[p].lazy = 0;
}

void update(int p, int s, int t, long long v) {
    if (seg[p].full_cover(s, t)) {
        seg[p].val += v * seg[p].len;
        seg[p].maxn += v;
        seg[p].lazy += v;
        seg[p].hlazy = max(seg[p].hlazy, seg[p].lazy);
        seg[p].hmax = max(seg[p].hmax, seg[p].maxn);
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
    seg[p].maxn = max(seg[p << 1].maxn, seg[p << 1 | 1].maxn);
    seg[p].hmax = max(seg[p << 1].hmax, seg[p << 1 | 1].hmax);
}

long long query_sum(int p, int s, int t) {
    if (seg[p].full_cover(s, t)) {
        return seg[p].val;
    }
    push_down(p);
    int mid = (seg[p].l + seg[p].r) >> 1;
    long long res = 0;
    if (s <= mid) {
        res += query_sum(p << 1, s, t);
    }
    if (t > mid) {
        res += query_sum(p << 1 | 1, s, t);
    }
    return res;
}

long long query_max(int p, int s, int t) {
    if (seg[p].full_cover(s, t)) {
        return seg[p].maxn;
    }
    push_down(p);
    int mid = (seg[p].l + seg[p].r) >> 1;
    long long res = -0x3f3f3f3f3f3f3f3f;
    if (s <= mid) {
        res = max(res, query_max(p << 1, s, t));
    }
    if (t > mid) {
        res = max(res, query_max(p << 1 | 1, s, t));
    }
    return res;
}

long long query_hmax(int p, int s, int t) {
    if (seg[p].full_cover(s, t)) {
        return seg[p].hmax;
    }
    push_down(p);
    int mid = (seg[p].l + seg[p].r) >> 1;
    long long res = -0x3f3f3f3f3f3f3f3f;
    if (s <= mid) {
        res = max(res, query_hmax(p << 1, s, t));
    }
    if (t > mid) {
        res = max(res, query_hmax(p << 1 | 1, s, t));
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
        cin >> x >> y;
        if (op == 1) {
            cin >> k;
            update(1, x, y, k);
        } else if (op == 2) {
            cin >> k;
            cout << "-1\n";
        } else if (op == 3) {
            cout << query_sum(1, x, y) << "\n";
        } else if (op == 4) {
            cout << query_max(1, x, y) << "\n";
        } else if (op == 5) {
            cout << query_hmax(1, x, y) << "\n";
        }
    }
    return 0;
}