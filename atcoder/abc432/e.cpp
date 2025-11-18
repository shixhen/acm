#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

int tree[N];
int a[N];
long long a2[N];
int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    if (x == 0) {
        tree[0] += v;
        return;
    }
    while (x < N) {
        tree[x] += v;
        x += lowbit(x);
    }
}

void add2(int x, long long v) {
    if (x == 0) {
        a2[0] += v;
        return;
    }
    while (x < N) {
        a2[x] += v;
        x += lowbit(x);
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= lowbit(x);
    }
    res += tree[0];
    return res;
}

long long query2(int x) {
    long long res = 0;
    while (x) {
        res += a2[x];
        x -= lowbit(x);
    }
    res += a2[0];
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //cout << 111 << endl;
        add(a[i], 1);
        add2(a[i], a[i]);
    }
    
    long long op, x, y, l, r, t;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            add(a[x], -1);
            add2(a[x], -a[x]);
            a[x] = y;
            add(a[x], 1);
            add2(a[x], a[x]);
        } else if (op == 2) {
            cin >> l >> r;
            if (r <= l) {
                cout << n * l << "\n";
                continue;
            }
            if (l == 0) {
                cout << query2(r - 1) + (n - query(r - 1)) * r << "\n";
                continue;
            }
            t = query2(r - 1) - query2(l - 1);
            cout << (long long) (n - query(r - 1)) * r + query(l - 1) * l + t << "\n";
        }
    }
    return 0;
}