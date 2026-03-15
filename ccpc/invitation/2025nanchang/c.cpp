#include <bits/stdc++.h>

using namespace std;

struct Seg_tree {
    vector<int> sum;
    vector<int> lazy;
    vector<int> mx;

    Seg_tree(int n) {
        sum.assign(n << 2, 0);
        lazy.assign(n << 2, 0);
        mx.assign(n << 2, 0);
    }

    void push_up(int u) {
        sum[u] = sum[u << 1] + sum[u << 1 | 1];
        mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
    }

    void push_down(int u, int l, int r) {
        if (lazy[u]) {
            int mid = (l + r) >> 1;
            sum[u << 1] += lazy[u] * (mid - l + 1);
            sum[u << 1 | 1] += lazy[u] * (r - mid);

            mx[u << 1] += lazy[u];
            mx[u << 1 | 1] += lazy[u];

            lazy[u << 1] += lazy[u];
            lazy[u << 1 | 1] += lazy[u];

            lazy[u] = 0;
        }
    }

    void update(int u, int l, int r, int ql, int qr, int v) {
        if (ql <= l && r <= qr) {
            sum[u] += v * (r - l + 1);
            mx[u] += v;
            lazy[u] += v;
            return;
        }
        push_down(u, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            update(u << 1, l, mid, ql, qr, v);
        }
        if (qr > mid) {
            update(u << 1 | 1, mid + 1, r, ql, qr, v);
        }
        push_up(u);
    }

    int query(int u, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return sum[u];
        }
        push_down(u, l, r);
        int mid = (l + r) >> 1;
        int res = 0;
        if (ql <= mid) {
            res += query(u << 1, l, mid, ql, qr);
        }
        if (qr > mid) {
            res += query(u << 1 | 1, mid + 1, r, ql, qr);
        }
        return res;
    }

    int query_max(int u, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return mx[u];
        }
        push_down(u, l, r);
        int mid = (l + r) >> 1;
        int res = 0;
        if (ql <= mid) {
            res = max(res, query_max(u << 1, l, mid, ql, qr));
        }
        if (qr > mid) {
            res = max(res, query_max(u << 1 | 1, mid + 1, r, ql, qr));
        }
        return res;
    }

};


void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> e(n);
    for (auto &[u, v] : e) {
        cin >> u >> v;
    }
    int ans = 0;
    int l = 0, r = -1;
    Seg_tree seg(n);
    while (r < n) {
        while (r < n && seg.query_max(1, 1, n, 1, n) <= k) {
            r++;
            if (r == n) {
                break;
            }
            seg.update(1, 1, n, e[r].first, e[r].second, 1);
        }
        ans = max(ans, r - l);
        if (r == n) {
            break;
        }
        seg.update(1, 1, n, e[l].first, e[l].second, -1);
        l++;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}