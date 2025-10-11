#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool vis[2][505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<string> s2(h);
    int sx, sy;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        s2[i] = s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            s2[i][j] = s[i][j];
            if (s[i][j] == 'x') {
                s2[i][j] = 'o';
            }
            if (s[i][j] == 'o') {
                s2[i][j] = 'x';
            }
            if (s[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    
    auto check = [&] (int x, int y) {
        bool res =  x < 0 || y < 0 || x >= h || y >= w || s[x][y] == '#';
        if (res) return true;
        return false;
    };
    queue<array<int, 4>> q;
    q.push({0, sx, sy, 0});
    while (q.size()) {
        auto [f, nx, ny, dis] = q.front();
        q.pop();
        if (s[nx][ny] == 'G') {
            cout << dis << "\n";
            return 0;
        }
        if (vis[f][nx][ny]) {
            continue;
        }
        vis[f][nx][ny] = true;
        for (int i = 0; i < 4; i++) {
            int nextx = nx + dx[i];
            int nexty = ny + dy[i];
            int nextf = f;
            if (check(nextx, nexty)) continue;
            if (s[nextx][nexty] == '?') {
                nextf = 1 - f;
            }
            if (f == 0 && s[nextx][nexty] == 'x') {
                continue;
            }
            if (f == 1 && s2[nextx][nexty] == 'x') {
                continue;
            }
            q.push({nextf, nextx, nexty, dis + 1});
        }

    }
    cout << -1;
    return 0;
}