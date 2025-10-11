#include <bits/stdc++.h>

using namespace std;

int n, m;
int g[1005][1005];

int cnt[1005][1005][4];


struct st {
	int x;
	int y;
	int s;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    char c;
    int ex, ey;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> c;
			g[i][j] = c - '0';
			if (c == '3') {
				ex = i;
				ey = j;
			}	
		}
	}
	cnt[ex][ey][0] = 1;
	queue<st> q;
	q.push({ex, ey, 0});
	while (q.size()) {
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().s;
		q.pop();

		if (s == 0) {
			if (y > 2 and cnt[x][y - 2][1] == 0) {
				if (g[x][y - 1] and g[x][y - 2]) {
					cnt[x][y - 2][1] = cnt[x][y][0] + 1;
					q.push({x, y - 2, 1});
				}
			}
			if (y <= m - 2 and cnt[x][y + 1][1] == 0) {
				if (g[x][y + 1] and g[x][y + 2]) {
					cnt[x][y + 1][1] = cnt[x][y][0] + 1;
					q.push({x, y + 1, 1});
				}
			}
			if (x > 2 and cnt[x - 2][y][2] == 0) {
				if (g[x - 2][y] and g[x - 1][y]) {
					cnt[x - 2][y][2] = cnt[x][y][0] + 1;
					q.push({x - 2, y, 2});
				}
			}
			if (x <= n - 2 and cnt[x + 1][y][2] == 0) {
				if (g[x + 2][y] and g[x + 1][y]) {
					cnt[x + 1][y][2] = cnt[x][y][0] + 1;
					q.push({x + 1, y, 2});
				}
			}
		} else if (s == 1) {
			if (y <= m - 2 and cnt[x][y + 2][0] == 0) {
				if (g[x][y + 2] == 1) {
					cnt[x][y + 2][0] = cnt[x][y][1] + 1;
					q.push({x, y + 2, 0});
				}
			}
			if (y > 1 and cnt[x][y - 1][0] == 0) {
				if (g[x][y - 1] == 1) {
					cnt[x][y - 1][0] = cnt[x][y][1] + 1;
					q.push({x, y - 1, 0});
				}
			}
			if (x > 1 and cnt[x - 1][y][1] == 0) {
				if (g[x - 1][y] and g[x - 1][y + 1]) {
					cnt[x - 1][y][1] = cnt[x][y][1] + 1;
					q.push({x - 1, y, 1});
				}
			}
			if (x < n and cnt[x + 1][y][1] == 0) {
				if (g[x + 1][y] and g[x + 1][y + 1]) {
					cnt[x + 1][y][1] = cnt[x][y][1] + 1;
					q.push({x + 1, y, 1});
				}
			}
		} else {
			if (y > 1 and cnt[x][y - 1][2] == 0) {
				if (g[x][y - 1] and g[x + 1][y - 1]) {
					cnt[x][y - 1][2] = cnt[x][y][2] + 1;
					q.push({x, y - 1, 2});
				}
			} 
			if (y < m and cnt[x][y + 1][2] == 0)  {
				if (g[x][y + 1] and g[x + 1][y + 1]) {
					cnt[x][y + 1][2] = cnt[x][y][2] + 1;
					q.push({x, y + 1, 2});
				}
			}
			if (x > 1 and cnt[x - 1][y][0] == 0) {
				if (g[x - 1][y] == 1) {
					cnt[x - 1][y][0] = cnt[x][y][2] + 1;
					q.push({x - 1, y, 0});
				}
			}
			if (x < n and cnt[x + 2][y][0] == 0) {
				if (g[x + 2][y] == 1) {
					cnt[x + 2][y][0] = cnt[x][y][2] + 1;
					q.push({x + 2, y, 0});
				}
			}
		}
	}
	int que;
	cin >> que;
	int a, b, xx;
	while (que--) {
		cin >> a >> b >> xx;
		if (cnt[a][b][xx]) {
			cout << cnt[a][b][xx] - 1 << "\n";
		} else {
			cout << "-1\n";
		}
	}
    return 0;
}