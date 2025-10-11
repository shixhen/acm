#include <bits/stdc++.h>

using namespace std;


vector<int> g[105];

int cnt[105];
int maxh;
int height[105];

void dfs(int now, int h, int p) {
    cnt[h]++;
    height[now] = h;
    maxh = max(maxh, h);
    for (int i = 0; i < g[now].size(); i++) {
        if (g[now][i] == p) continue;
        dfs(g[now][i], h + 1, now);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 0);
    int width = 0;
    for (int i = 1; i <= n; i++) {
        width = max(width, cnt[i]);
    }
    cout << maxh << "\n";
    cout << width << "\n";
    int x, y;
    cin >> x >> y;
    int ans = height[x] * 2 + height[y];
    while (x != y) {
        if (height[x] > height[y]) {
            for (int i = 0; i < g[x].size(); i++) {
                if (height[g[x][i]] == height[x] - 1) {
                    x = g[x][i];
                    break;
                }
            }
        } else {
            for (int i = 0; i < g[y].size(); i++) {
                if (height[g[y][i]] == height[y] - 1) {
                    y = g[y][i];
                    break;
                }
            }
        }
    }
    ans -= height[x] * 3;
    cout << ans << "\n";
    return 0;
}