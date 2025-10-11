#include <bits/stdc++.h>

using namespace std;

vector<int> f;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    f.assign(n * 2 + 1, 0);
    iota(f.begin(), f.end(), 0);
    int op1, op2, x, y, u, v, p, q;
    while (m--) {
        cin >> x >> op1 >> y >> op2;
        u = op1 ? x : x + n;
        v = op2 ? y + n : y;
        u = find(u);
        v = find(v);
        p = !op1 ? x : x + n;
        q = !op2 ? y + n : y;
        p = find(p);
        q = find(q);
        if (u != v) f[u] = v;
        if (p != q) f[p] = q;
    }
    
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        a.emplace_back(find(i), i);
        a.emplace_back(find(i + n), -i);
    }
    sort(a.begin(), a.end());
    vector<bool> vis(n + 1, false);
    vector<int> ans(n + 1, 0);
    cout << "POSSIBLE\n";
    for (auto &[x, y] : a) {
        if (!vis[abs(y)]) {
            if (y > 0) ans[y] = 1;
            vis[abs(y)] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}