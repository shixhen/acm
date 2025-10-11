#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4 + 5;

vector<int> e[N];
vector<int> se[N];
int dfn[N];
int low[N];
int scc[N];
int val[N];
int a[N];
int d[N];
int ind[N];
bool in_stk[N];
int sc, cnt, n, m;
stack<int> stk;

void tarjan(int u) {
    low[u] = dfn[u] = ++cnt;
    stk.push(u);
    in_stk[u] = true;
    for (int v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++sc;
        while (true) {
            int x = stk.top();
            stk.pop();
            in_stk[x] = false;
            scc[x] = sc;
            val[sc] += a[x];
            if (x == u) break;
        }
    }
}

int topo() {
    queue<int> q;
    for (int i = 1; i <= sc; i++) {
        if (ind[i] == 0) {
            q.push(i);
            d[i] = val[i];
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto &v : se[u]) {
            d[v] = max(d[v], d[u] + val[v]);
            if (--ind[v] == 0) q.push(v);
        }
    }
    return *max_element(d + 1, d + sc + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (auto &v : e[u]) {
            if (scc[u] != scc[v]) {
                se[scc[u]].push_back(scc[v]);
                ind[scc[v]]++;
            }
        }
    }
    cout << topo();
    return 0;
}