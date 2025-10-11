#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

map<long long, long long> mp;

bool work(int x, int y, int sx, int sy, int c[][3]) {
    if (x < 0 || x > 2 || y < 0 || y > 2) return false;
    swap(c[x][y], c[sx][sy]);
    return true;
}

long long change(int c[][3]) {
    long long res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res = res * 10 + c[i][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n;
    cin >> n;
    mp[n] = 0;
    int c[3][3], x, y;
    queue<long long> q;
    q.push(n);
    while (q.size()) {
        long long cur = q.front();
        q.pop();
        if (cur == 123804765) {
            cout << mp[cur] << endl;
            return 0;
        }
        long long temp = cur;
        for (int i = 2; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                c[i][j] = temp % 10;
                temp /= 10;
                if (c[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            bool f = work(nx, ny, x, y, c);
            if (!f) continue;
            long long next = change(c);
            if (!mp.count(next)) {
                mp[next] = mp[cur] + 1;
                q.push(next);
            }
            work(x, y, nx, ny, c);
        }
    }
    return 0;
}