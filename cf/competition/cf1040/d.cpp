#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

void add(int idx, int v, vector<int>& tree) {
    while (idx < tree.size()) {
        tree[idx] += v;
        idx += lowbit(idx);
    }
    return;
}

int query(int idx, const vector<int>& tree) {
    int res = 0;
    while (idx) {
        res += tree[idx];
        idx -= lowbit(idx);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> t1(n + 5);
    vector<int> t2(n + 5);
    for (int i = 1; i <= n; i++) {
        add(a[i], 1, t2);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(a[i], -1, t2);
        int minr = query(a[i] - 1, t2);
        int cntl = query(n, t1) - query(a[i], t1);
        int cntr = query(n,  t2) - query(a[i] - 1, t2);
        //cout << i << "      " << minr << " " << cntl << " " << cntr << "\n";
        ans += min(minr, cntr - cntl + minr);
        add(a[i], 1, t1);
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}