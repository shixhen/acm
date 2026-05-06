#include <bits/stdc++.h>

using namespace std;

static const long long INF = (1LL << 62);

static long long add_inf(long long x, long long y) {
    if (x >= INF / 4 || y >= INF / 4) {
        return INF;
    }
    long long s = x + y;
    return s >= INF ? INF : s;
}

struct Mat {
    long long a[2][2];
};

static Mat mat_id() {
    Mat m;
    m.a[0][0] = 0;
    m.a[0][1] = INF;
    m.a[1][0] = INF;
    m.a[1][1] = 0;
    return m;
}

static Mat mat_mul(const Mat &x, const Mat &y) {
    Mat r;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            r.a[i][j] = min(add_inf(x.a[i][0], y.a[0][j]), add_inf(x.a[i][1], y.a[1][j]));
        }
    }
    return r;
}

static bool mat_is_id(const Mat &m) {
    return m.a[0][0] == 0 && m.a[0][1] >= INF / 2 && m.a[1][0] >= INF / 2 && m.a[1][1] == 0;
}

static Mat mat_step(long long w) {
    Mat m;
    m.a[0][0] = INF;
    m.a[0][1] = 0;
    m.a[1][0] = w;
    m.a[1][1] = w;
    return m;
}

struct SegTree {
    int n;
    vector<long long> mn0;
    vector<long long> mn1;
    vector<Mat> lazy;

    explicit SegTree(int n_) : n(n_) {
        mn0.assign(4 * n + 5, INF);
        mn1.assign(4 * n + 5, INF);
        lazy.assign(4 * n + 5, mat_id());
    }

    void apply(int idx, const Mat &m) {
        long long n0 = min(add_inf(m.a[0][0], mn0[idx]), add_inf(m.a[0][1], mn1[idx]));
        long long n1 = min(add_inf(m.a[1][0], mn0[idx]), add_inf(m.a[1][1], mn1[idx]));
        mn0[idx] = n0;
        mn1[idx] = n1;
        lazy[idx] = mat_mul(m, lazy[idx]);
    }

    void push(int idx) {
        if (mat_is_id(lazy[idx])) {
            return;
        }
        apply(idx * 2, lazy[idx]);
        apply(idx * 2 + 1, lazy[idx]);
        lazy[idx] = mat_id();
    }

    void pull(int idx) {
        mn0[idx] = min(mn0[idx * 2], mn0[idx * 2 + 1]);
        mn1[idx] = min(mn1[idx * 2], mn1[idx * 2 + 1]);
    }

    void range_apply(int idx, int l, int r, int ql, int qr, const Mat &m) {
        if (ql > r || qr < l) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(idx, m);
            return;
        }
        push(idx);
        int mid = (l + r) / 2;
        range_apply(idx * 2, l, mid, ql, qr, m);
        range_apply(idx * 2 + 1, mid + 1, r, ql, qr, m);
        pull(idx);
    }

    void point_set(int idx, int l, int r, int pos, long long val) {
        if (l == r) {
            mn0[idx] = INF;
            mn1[idx] = val;
            lazy[idx] = mat_id();
            return;
        }
        push(idx);
        int mid = (l + r) / 2;
        if (pos <= mid) {
            point_set(idx * 2, l, mid, pos, val);
        } else {
            point_set(idx * 2 + 1, mid + 1, r, pos, val);
        }
        pull(idx);
    }

    long long range_query_min1(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return INF;
        }
        if (ql <= l && r <= qr) {
            return mn1[idx];
        }
        push(idx);
        int mid = (l + r) / 2;
        return min(range_query_min1(idx * 2, l, mid, ql, qr),
                   range_query_min1(idx * 2 + 1, mid + 1, r, ql, qr));
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegTree st(n);
    long long ans = INF;
    for (int r = 1; r <= n; r++) {
        if (r > 1) {
            st.range_apply(1, 1, n, 1, r - 1, mat_step(a[r]));
        }
        st.point_set(1, 1, n, r, a[r]);
        if (r >= k) {
            long long cur = st.range_query_min1(1, 1, n, 1, r - k + 1);
            ans = min(ans, cur);
        }
    }

    cout << ans << "\n";
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