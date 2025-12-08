#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

long long sum[N << 2];
long long lazy[N << 2];

void build(int p, int l, int r) {
    if (l == r) {
        cin >> sum[p];
        lazy[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void push_down(int p, int l, int r) {
    if (lazy[p] == 0) {
        return;
    }
    int mid = (l + r) >> 1;
    sum[p << 1] += lazy[p] * (mid - l + 1);
    sum[p << 1 | 1] += lazy[p] * (r - mid);
    lazy[p << 1] += lazy[p];
    lazy[p << 1 | 1] += lazy[p];
    lazy[p] = 0;
}

void update(int p, int l, int r, int s, int t, const long long &v) {
    if (s <= l && r <= t) {
        sum[p] += v * (r - l + 1);
        lazy[p] += v;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (s <= mid) {
        update(p << 1, l, mid, s, t, v);
    }
    if (t > mid) {
        update(p << 1 | 1, mid + 1, r, s, t, v);
    }
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

long long query(int p, int l, int r, int s, int t) {
    if (s <= l && r <= t) {
        return sum[p];
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (s <= mid) {
        res += query(p << 1, l, mid, s, t);
    }
    if (t > mid) {
        res += query(p << 1 | 1, mid + 1, r, s, t);
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    int op, x, y, k;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        } else if (op == 2) {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}