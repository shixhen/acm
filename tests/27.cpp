#include <bits/stdc++.h>
#define N 200005
using namespace std;
using ll = long long;

int n;

int a[105][300];
int b[105][300];

bool check(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > 2 * x - 1 || b[x][y] > 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= 2 * i - 1; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ex, ey;
    cin >> ex >> ey;
    queue<array<int, 2>> q;
    b[1][1] = 1;
    q.push({1, 1});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        // cout << x << " " << y << endl;
        if (x == ex && y == ey) {
            cout << b[x][y] - 1 << "\n";
            return 0;
        }
        int tx, ty;
        if (x % 2) {
            tx = x;
            ty = y + 1;
            if (check(tx, ty) && a[tx][ty] == (a[x][y] + 3) % 4) {
                b[tx][ty] = b[x][y] + 1;
                q.push({tx, ty});
            }
            ty = y - 1;
            if (check(tx, ty) && a[tx][ty] == (a[x][y] + 1) % 4) {
                b[tx][ty] = b[x][y] + 1;
                q.push({tx, ty});
            }
            if (a[x][y] % 2) {
                tx = x + 1;
                ty = y + 1;
                if (check(tx, ty) && a[tx][ty] == (a[x][y] + 2) % 4) {
                    b[tx][ty] = b[x][y] + 1;
                    q.push({tx, ty});
                }
                tx = x - 1;
                ty = y - 1;
                if (check(tx, ty) && a[tx][ty] == (a[x][y] + 2) % 4) {
                    b[tx][ty] = b[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        } else {
            tx = x;
            ty = y + 1;

            if (check(tx, ty) && a[tx][ty] == (a[x][y] + 1) % 4) {
                b[tx][ty] = b[x][y] + 1;
                q.push({tx, ty});
            }
            ty = y - 1;
            if (check(tx, ty) && a[tx][ty] == (a[x][y] + 3) % 4) {
                b[tx][ty] = b[x][y] + 1;
                q.push({tx, ty});
            }
            if (a[x][y] % 2 == 0) {
                tx = x + 1;
                ty = y + 1;

                if (check(tx, ty) && a[tx][ty] == (a[x][y] + 2) % 4) {
                    b[tx][ty] = b[x][y] + 1;
                    q.push({tx, ty});
                }
                tx = x - 1;
                ty = y - 1;
                if (check(tx, ty) && a[tx][ty] == (a[x][y] + 2) % 4) {
                    b[tx][ty] = b[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}