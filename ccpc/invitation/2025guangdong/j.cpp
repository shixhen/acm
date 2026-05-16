#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
long long dis[N];
vector<vector<pair<long long, int>>> g(N);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i] = 0x3f3f3f3f3f3f3f3fLL;
        if (a[i] == 0) {
            pq.push({0, -i});
        }
    }
    
    for (int i = 1; i <= k; i++) {
        int t, sc;
        cin >> t >> sc;
        for (int j = 1; j <= sc; j++) {
            int x;
            cin >> x;
            pq.push({t, -x});
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[abs(u)] != 0x3f3f3f3f3f3f3f3fLL) {
            continue;
        }
        if (u < 0) {
            u = -u;
            dis[u] = d;
            for (auto [w, v] : g[u]) {
                pq.push({d + w, v});
            }
        } else {
            a[u]--;
            if (a[u] <= 0) {
                dis[u] = d;
                for (auto [w, v] : g[u]) {
                    pq.push({d + w, v});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0x3f3f3f3f3f3f3f3fLL) {
            cout << -1 << " ";
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}