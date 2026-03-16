#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & (-x);
}

int tree[200005];

int n;

int add(int idx, int val) {
    while (idx <= n) {
        tree[idx] += val;
        idx += lowbit(idx);
    }
    return 0;
}

int query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += tree[idx];
        idx -= lowbit(idx);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1, x; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q--) {
        int op;
        cin >> op;
        int x, l, r;
        if (op == 1) {
            cin >> x;
            add(x, -a[x]);
            add(x + 1, -a[x + 1]);
            swap(a[x], a[x + 1]);
            add(x, a[x]);
            add(x + 1, a[x + 1]);
        } else if (op == 2) {
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }
    return 0;
}