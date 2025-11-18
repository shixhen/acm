#include <bits/stdc++.h>

using namespace std;

struct edge {
    int t, w;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph(n + 1);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    return 0;
}