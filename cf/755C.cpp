#include <bits/stdc++.h>

using namespace std;

bitset<10005> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x, u, v;
    cin >> n;
    vector<int> f(n + 1);
    iota(f.begin(), f.end(), 0);
    const function<int(int)> find = [&](int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    };

    for (int i = 1; i <= n; i++) {
        cin >> x;
        u = find(i);
        v = find(x);
        if (u != v) {
            f[u] = v;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        u = find(i);
        if (!vis[u]) {
            ans++;
        }
        vis[u] = 1;
    }
    cout << ans << endl;
    return 0;
}