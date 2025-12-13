#include <bits/stdc++.h>

using namespace std;


string a[1005];

int b[1005][1005];
set<pair<int, int>> s[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    a[0] = string(w + 2, '#');
    for (int i = 1; i <= h; i++) {
        cin >> a[i];
        a[i] = "#" + a[i] + "#";
        for (int j = 1; j <= w; j++) {
            if ('a' <= a[i][j] && a[i][j] <= 'z') {
                s[a[i][j] - 'a'].insert({i, j});
            }
        }
    }
    a[h + 1] = string(w + 2, '#');
    queue<pair<int, int>> q;
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            b[i][j] = 0x3f3f3f3f;
        }
    }
    q.push({1, 1});
    b[1][1] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (a[nx][ny] == '#' || b[nx][ny] <= b[x][y] + 1) {
                continue;
            }
            b[nx][ny] = b[x][y] + 1;
            q.push({nx, ny});
        }
        if ('a' <= a[x][y] && a[x][y] <= 'z') {
            int idx = a[x][y] - 'a';
            for (auto [nx, ny] : s[idx]) {
                if (b[nx][ny] <= b[x][y] + 1) {
                    continue;
                }
                b[nx][ny] = b[x][y] + 1;
                q.push({nx, ny});
            }
            s[idx].clear();
        }
    }
    if (b[h][w] == 0x3f3f3f3f) {
        cout << -1 << "\n";
    } else {
        cout << b[h][w] << "\n";
    }
    return 0;
}