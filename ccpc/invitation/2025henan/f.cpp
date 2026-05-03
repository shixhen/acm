#include <bits/stdc++.h>

using namespace std;

vector<string> g;

int n, m;

struct node {
    int x;
    int y;
    int k;
    int f;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<pair<int, int>> start;

bool check(int ans) {
    queue<node> q;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, false));
    for (auto &[x, y] : start) {
        q.push({x, y, ans, 0});
    }
    while (!q.empty()) {
        auto [x, y, k, f] = q.front();
        q.pop();
        if (k == 0) f = 0;
        if (vis[x][y]) continue;
        // cout << x << " " << y << " " << k << " " << f << endl;
        if (x == n && y == m) return true;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (f) {
                q.push({nx, ny, k - 1, f});
            } else {
                if (g[nx][ny] == '.') {
                    q.push({nx, ny, k, 0});
                } else if (g[nx][ny] == '#' && k > 0) {
                    q.push({nx, ny, k - 1, 1});
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    g.assign(n + 2, "0");
    g[0] = string(m + 2, '0');
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] = "0" + g[i] + "0";
    }
    g[n + 1] = string(m + 2, '0');
    int l = 0, r = n * m;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, false));
    q.push({1, 1});
    start.clear();
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        start.push_back({x, y});
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (g[nx][ny] == '.') {
                q.push({nx, ny});
            }
        }
    }
    // check(1);
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";

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