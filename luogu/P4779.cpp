#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = 0x3f3f3f3f3f3f3f3f;

// 边
struct edge {
    int to;
    int w;
};

// 用邻接表存图
vector<vector<edge>> g;
// 最短路数组
vector<long long> dis;  
// 访问标记数组
vector<int> vis;

// 起点
int s;

void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        // 每个点的最短路确定后不会更新，且只遍历一次邻边
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto &e : g[u]) {
            int v = e.to;
            int w = e.w;

            // 松弛操作,并且判断是否更新最短路，减少入队操作
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m >> s;
    dis.assign(n + 1, inf);
    g.assign(n + 1, vector<edge>());
    vis.assign(n + 1, 0);

    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra();
    
    for (int i = 1; i <= n; i++) {
        // 判断是否不可达
        if (dis[i] == inf) {
            cout << INT_MAX << " ";
        } else {
            cout << dis[i] << " ";
        }
    }
    return 0;
}