#include <bits/stdc++.h>

using namespace std;


int v[1005][1005];
int a[1005][1005];
int vis[1005][1005];

int n, m, x, y, t;

bool check2(int x, int y, int time, int money) {
    return x >= 1 && x <= n && y >= 1 && y <= m && time < a[x][y] && money > vis[x][y];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    memset(a, 0x3f, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> x >> y >> t;
        a[x][y] = min(a[x][y], t);
    }
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> q;
    q.push({0, v[1][1], 1, 1});
    int ans = 0;
    while (q.size()) {
        int money = q.top()[1];
        int x= q.top()[2];
        int y = q.top()[3];
        int time = q.top()[0];
        q.pop();
        if (money < vis[x][y]) continue;
        ans = max(ans, money);
        vis[x][y] = money;
        time++;
        x++;
        if (check2(x, y, time, money + v[x][y])) {
            q.push({time, money + v[x][y], x, y});
            vis[x][y] = money + v[x][y];
        }
        x--;
        y++;
        if (check2(x, y, time, money + v[x][y])) {
            q.push({time, money + v[x][y], x, y});
            vis[x][y]= money + v[x][y];
        }
    }
    cout << ans;
    return 0;
}