#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> f;
vector<int> s;
vector<int> dep;
vector<int> son;

void dfs(int u, int fa) {
    s[u] = 1;
    f[u] = fa;
    for (auto v : g[u]) {
        if (v == fa) {
            continue;
        }
        dep[v] = dep[u] + 1;
        s[u]++;
        dfs(v, u);
        son[u] = v;
    }
}

void solve() {
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    f.assign(n + 1, 0);
    son.assign(n + 1, 0);
    vector<int> vis(n + 1);
    vector<int> d(n + 1);
    dep.assign(n + 1, 0);
    s.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, 0);
    vector<int> cnt(n + 1);
    int maxd = 0;
    
    for (int i = 1; i <= n; i++) {
        cnt[dep[i]]++;
        maxd = max(maxd, dep[i]);
    }
    vector<vector<int>> layers(maxd + 1, vector<int>());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        layers[dep[i]].push_back(i);
        ans = max(ans, cnt[i]);
        ans = max(ans, s[i]);
    }
    
    cout << ans << "\n";
    vector<vector<int>> res(ans + 1, vector<int>());
    res[1].push_back(1);
    d[1] = 1;
    set<int> pos;
    for (int i = 1; i <= ans; i++) {
        pos.insert(i);
    }
    for (int i = 1; i < maxd; i++) {
        vector<int> temp;
        vector<int> p;
        for (auto u : layers[i]) {
            if (son[u]) {
                p.push_back(u);
            }
        }
        if (p.size() == 1) {
            pos.erase(d[p[0]]);
            temp.push_back(d[p[0]]);
            for (auto v : g[p[0]]) {
                if (v == f[p[0]]) {
                    continue;
                }
                int color = *pos.begin();
                d[v] = color;
                res[d[v]].push_back(v);
                pos.erase(color);
                temp.push_back(color);
            }
            for (auto c : temp) {
                pos.insert(c);
            }
            continue;
        }
        for (int j = 0; j < p.size(); j++) {
            int nxt = (j + 1) % p.size();
            int color = d[p[nxt]];
            d[son[p[j]]] = color;
            res[color].push_back(son[p[j]]);
            pos.erase(color);
            temp.push_back(color);
        }
        for (auto u : layers[i]) {
            for (auto v : g[u]) {
                if (v == f[u] || v == son[u]) {
                    continue;
                }
                int color = *pos.begin();
                d[v] = color;
                res[d[v]].push_back(v);
                pos.erase(color);
                temp.push_back(color);
            }
        }
        for (auto c : temp) {
            pos.insert(c);
        }
    }
    for (int i = 1; i <= ans; i++) {
        cout << res[i].size();
        for (auto v : res[i]) {
            cout << " " << v;
        }
        cout << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}