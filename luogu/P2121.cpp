#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

int f[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

struct e {
    long long u, v, w;
    bool operator < (const e& other) const {
        return w > other.w;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    iota(f, f + N, 0);
    int u, v, w;
    vector<e> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end());
    long long ans = 0;
    for (const auto& e : edges) {
        u = find(e.u);
        v = find(e.v);
        if (f[u] != v) {
            f[u] = v;
            ans += e.w;
            k--;
            if (k == 0) {
                cout << ans;
                return 0;
            }
        }

    }
    return 0;
}