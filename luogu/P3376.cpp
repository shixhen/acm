#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct edge {
    // 边的终点，反向边，容量
    int to, rev;
    i64 cap;
};

class Dinic {
private:
    int n;
    vector<vector<edge>> adj;
    vector<int> level, ptr;

    bool bfs(int s, int t) {
        level.assign(n, -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto& e : adj[u]) {
                if (level[e.to] == -1 && e.cap > 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    i64 dfs(int s, int t, i64 flow) {
        if (s == t)
            return flow;
        for (int &i = ptr[s]; i < adj[s].size(); i++) {
            edge& e = adj[s][i];
            if (level[e.to] == level[s] + 1 && e.cap > 0) {
                i64 d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    adj[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int n): n(n), adj(n) {};

    void add_edge(int u, int v, int cap) {
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0});
    }

    i64 max_flow(int s, int t) {
        i64 flow = 0, f;
        while (bfs(s, t)) {
            ptr.assign(n, 0);
            while (f = dfs(s, t, INT_MAX)) {
                flow += f;
            }
        }
        return flow;
    }   

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int u, v, w;
    Dinic dic(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dic.add_edge(u, v, w);
    }
    cout << dic.max_flow(s, t);
    return 0;
}