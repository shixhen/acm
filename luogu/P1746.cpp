#include <iostream>
#include <cstdio>
#include <queue>


using namespace std;

int a[1005][1005];
int n;
int x1, y_1, x2, y2;

bool check(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] == 0 && (x != x1 || y != y_1)) return true;
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    cin >> x1 >> y_1 >> x2 >> y2;
    queue<pair<int, int>> q;
    q.push({x1, y_1});
    while(q.size()) {
        int nx = q.front().first;
        int ny = q.front().second;
        int now = a[nx][ny];
        q.pop();
        if (nx == x2 && ny == y2) {
            cout << now;
            return 0;
        }
        nx--;
        if (check(nx, ny)) {
            q.push({nx, ny});
            a[nx][ny] = now + 1;
        }
        nx++;
        ny++;
        if (check(nx, ny)) {
            q.push({nx, ny});
            a[nx][ny] = now + 1;
        }
        ny--;
        ny--;
        if (check(nx, ny)) {
            q.push({nx, ny});
            a[nx][ny] = now + 1;
        }
        ny++;
        nx++;
        if (check(nx, ny)) {
            q.push({nx, ny});
            a[nx][ny] = now + 1;
        }
    }
    return 0;
}