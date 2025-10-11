#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, op, l, r, k, v;

struct segment_tree {
    ll sum;
    int l, r, maxa, cnt, se, maxb;
    int add1, add2, add3, add4;
} s[2000005];

inline void push_up(int p) {
    s[p].sum = s[p * 2].sum + s[p * 2 + 1].sum;
    s[p].maxa = max(s[p * 2].maxa, s[p * 2 + 1].maxa);
    s[p].maxb = max(s[p * 2].maxb, s[p * 2 + 1].maxb);

    if (s[p * 2].maxa == s[p * 2 + 1].maxa) {
        s[p].se = max(s[p * 2].se, s[p * 2 + 1].se);
        s[p].cnt = s[p * 2].cnt + s[p * 2 + 1].cnt;
    } else if (s[p * 2].maxa > s[p * 2 + 1].maxa) {
        s[p].se = max(s[p * 2].se, s[p * 2 + 1].maxa);
        s[p].cnt = s[p * 2].cnt;
    } else {
        s[p].se = max(s[p * 2].maxa, s[p * 2 + 1].se);
        s[p].cnt = s[p * 2 + 1].cnt;
    }
}

void build(int l, int r, int p) {
    s[p].l = l, s[p].r = r;
    if (l == r) {
        cin >> s[p].sum;
        s[p].maxa = s[p].maxb = s[p].sum;
        s[p].cnt = 1;
        s[p].se = -2000000000;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    push_up(p);
}

inline void change(int k1, int k2, int k3, int k4, int p) {
    s[p].sum += 1ll * k1 * s[p].cnt + 1ll * k2 * (s[p].r - s[p].l + 1 - s[p].cnt);
    s[p].maxb = max(s[p].maxb, s[p].maxa + k3);
    s[p].maxa += k1;
    if (s[p].se != -2000000000) s[p].se += k2;
    s[p].add3 = max(s[p].add3, s[p].add1 + k3);
    s[p].add4 = max(s[p].add4, s[p].add2 + k4);
    s[p].add1 += k1;
    s[p].add2 += k2;
}

inline void push_down(int p) {
    int maxn = max(s[p * 2].maxa, s[p * 2 + 1].maxa);
    if (s[p * 2].maxa == maxn)
        change(s[p].add1, s[p].add2, s[p].add3, s[p].add4, p * 2);
    else
        change(s[p].add2, s[p].add2, s[p].add4, s[p].add4, p * 2);

    if (s[p * 2 + 1].maxa == maxn)
        change(s[p].add1, s[p].add2, s[p].add3, s[p].add4, p * 2 + 1);
    else
        change(s[p].add2, s[p].add2, s[p].add4, s[p].add4, p * 2 + 1);

    s[p].add1 = s[p].add2 = s[p].add3 = s[p].add4 = 0;
}

void update_add(int p) {
    if (l > s[p].r || r < s[p].l) return;
    if (l <= s[p].l && s[p].r <= r) {
        s[p].sum += 1ll * k * s[p].cnt + 1ll * k * (s[p].r - s[p].l + 1 - s[p].cnt);
        s[p].maxa += k;
        s[p].maxb = max(s[p].maxb, s[p].maxa);
        if (s[p].se != -2000000000) s[p].se += k;
        s[p].add1 += k;
        s[p].add2 += k;
        s[p].add3 = max(s[p].add3, s[p].add1);
        s[p].add4 = max(s[p].add4, s[p].add2);
        return;
    }
    push_down(p);
    update_add(p * 2);
    update_add(p * 2 + 1);
    push_up(p);
}

void update_min(int p) {
    if (l > s[p].r || r < s[p].l || v >= s[p].maxa) return;
    if (l <= s[p].l && s[p].r <= r && s[p].se < v) {
        int k = s[p].maxa - v;
        s[p].sum -= 1ll * s[p].cnt * k;
        s[p].maxa = v;
        s[p].add1 -= k;
        return;
    }
    push_down(p);
    update_min(p * 2);
    update_min(p * 2 + 1);
    push_up(p);
}

ll query_sum(int p) {
    if (l > s[p].r || r < s[p].l) return 0;
    if (l <= s[p].l && s[p].r <= r) return s[p].sum;
    push_down(p);
    return query_sum(p * 2) + query_sum(p * 2 + 1);
}

int query_maxa(int p) {
    if (l > s[p].r || r < s[p].l) return -2000000000;
    if (l <= s[p].l && s[p].r <= r) return s[p].maxa;
    push_down(p);
    return max(query_maxa(p * 2), query_maxa(p * 2 + 1));
}

int query_maxb(int p) {
    if (l > s[p].r || r < s[p].l) return -2000000000;
    if (l <= s[p].l && s[p].r <= r) return s[p].maxb;
    push_down(p);
    return max(query_maxb(p * 2), query_maxb(p * 2 + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    build(1, n, 1);
    while (m--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            update_add(1);
        } else if (op == 2) {
            cin >> v;
            update_min(1);
        } else if (op == 3) {
            cout << query_sum(1) << '\n';
        } else if (op == 4) {
            cout << query_maxa(1) << '\n';
        } else {
            cout << query_maxb(1) << '\n';
        }
    }
    return 0;
}
