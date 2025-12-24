#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
int b[] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};

int n, q, x;

struct info {
    int cnt[16];
    info() {
        for (int i = 0; i < 16; i++) {
            cnt[i] = 0;
        }
    }
    info(int arr[]) {
        for (int i = 0; i < 16; i++) {
            cnt[i] = arr[i];
        }
    }

    void init() {
        for (int i = 0; i < 16; i++) {
            cnt[i] = i;
        }
    }

    info operator +(const info &other) const {
        info result;
        for (int i = 0; i < 16; i++) {
            result.cnt[i] = cnt[i] + other.cnt[i];
        }
        return result;
    }

    bool operator !=(const info &other) const {
        for (int i = 0; i < 16; i++) {
            if (cnt[i] != other.cnt[i]) return true;
        }
        return false;
    }

    void apply_sum(const info &other) {
        info temp;
        for (int i = 0; i < 16; i++) {
            temp.cnt[other.cnt[i]] += cnt[i];
        }
        *this = temp;
    }

    void apply_lazy(const info &other) {
        info temp;
        for (int i = 0; i < 16; i++) {
            temp.cnt[i] = other.cnt[cnt[i]];
        }
        *this = temp;
    }

    bool is_init() {
        for (int i = 0; i < 16; i++) {
            if (cnt[i] != i) return false;
        }
        return true;
    }
};

info sum[N << 2], lazy[N << 2], infoa(a), infob(b);

void build(int p, int l, int r) {
    lazy[p].init();
    if (l == r) {
        cin >> x;
        sum[p].cnt[x]++;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void push_down(int p) {
    if (!lazy[p].is_init()) {
        sum[p << 1].apply_sum(lazy[p]);
        sum[p << 1 | 1].apply_sum(lazy[p]);
        lazy[p << 1].apply_lazy(lazy[p]);
        lazy[p << 1 | 1].apply_lazy(lazy[p]);
        lazy[p].init();
    }
}

void update1(int p, int l, int r, int s, int t) {
    if (l >= s && r <= t) {
        sum[p].apply_sum(infoa);
        lazy[p].apply_lazy(infoa);
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (s <= mid) update1(p << 1, l, mid, s, t);
    if (t > mid) update1(p << 1 | 1, mid + 1, r, s, t);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
    return;
}

void update2(int p, int l, int r, int s, int t) {
    if (l >= s && r <= t) {
        sum[p].apply_sum(infob);
        lazy[p].apply_lazy(infob);
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (s <= mid) update2(p << 1, l, mid, s, t);
    if (t > mid) update2(p << 1 | 1, mid + 1, r, s, t);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

info query(int p, int l, int r, int s, int t) {
    if (l >= s && r <= t) {
        return sum[p];
    }
    push_down(p);
    int mid = (l + r) >> 1;
    info res;
    if (s <= mid) res = res + query(p << 1, l, mid, s, t);
    if (t > mid) res = res + query(p << 1 | 1, mid + 1, r, s, t);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    build(1, 1, n);
    int op, l, r;
    while (q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            update1(1, 1, n, l, r);
        } else if (op == 2) {
            update2(1, 1, n, l, r);
        } else {
            info res = query(1, 1, n, l, r);
            int ans = 0;
            for (int i = 0; i < 16; i++) {
                ans ^= res.cnt[i];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}