#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> f;
    
    void init(int n) {
        f.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        int u = find(x), v = find(y);
        if (u != v) {
            f[u] = v;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
} dsu;

struct Graph {
    vector<vector<int>> e;
    vector<int> vis;
    Graph(int n) : e(n + 1), vis(n + 1) {}

    void clear() {
        for (auto &v: vis) {
            v = 0;
        }
    }

    void add_edge(int u, int v) {
        e[u].push_back(v);
    }

    void dfs(int u) {
        vis[u] = 1;
        for (auto v: e[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    vector<int> cnt(n + 1);
    vector<int> id(n + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        id[i] = i;
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            g[i][j] = s[j - 1] - '0';
            cnt[i] += g[i][j];
        }
    }
    sort(id.begin() + 1, id.end(), [&] (int x, int y) {
        return cnt[x] > cnt[y];
    });
    vector<pair<int, int>> edges;
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            int x = id[v];
            //cout << u << " " << x << " " << v << "\n";
            if (!vis[x] && g[u][x]) {
                edges.emplace_back(u, x);
                //cout << u << " " << x << "\n";
                if (edges.size() >= n) {
                    cout << "NO\n";
                    return;
                }
                for (int w = 1; w <= n; w++) {
                    if (g[x][w]) {
                        vis[w] = 1;
                    }
                }
            }
            
            
        }
    }
    if (edges.size() != n - 1) {
        cout << "NO\n";
        return;
    }

    dsu.init(n);
    for (auto &[u, v]: edges) {
        dsu.merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dsu.same(1, i)) {
            cout << "NO\n";
            return;
        }
    }
    Graph graph(n);
    for (auto &[u, v]: edges) {
        graph.add_edge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        graph.clear();
        graph.dfs(i);
        for (int j = 1; j <= n; j++) {
            if (graph.vis[j] && !g[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (auto &[u, v]: edges) {
        cout << u << " " << v << "\n";
    }
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