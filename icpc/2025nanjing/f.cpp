#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[1 << 12][1005];
int find(int v, int x) { return (f[v][x] == x) ? x : f[v][x] = find(v, f[v][x]); }

void bfs(int x, int u, int v) {
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (find(cur, u) == find(cur, v)) continue;
        f[cur][find(cur, u)] = find(cur, v);
        //cout << cur << endl;
        for (int i = 0; i < 12; i++) {
            if (cur & (1 << i)) {
                q.push(cur - (1 << i));
            }
        }
    }
    return;
}

void solve() {
    int n, T;
    cin >> n >> T;
    for (int i = 0; i <= (1 << 12) - 1; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = j;
        }
    }
    char op;
    int u, v, w;
    long long sum = 0;
    while (T--) {
        cin >> op;
        if (op == '+') {
            cin >> u >> v >> w;
            bfs(w, u, v);
            
        } else {
            cin >> u >> v;
            if (find(0, u) != find(0, v)) {
                sum--;
                continue;
            }
            int ans = 0;
            for (int i = 11; i >= 0; i--) {
                if (find(ans | (1 << i), u) == find(ans | (1 << i), v)) {
                    ans |= (1 << i);
                }
            }
            sum += ans;
        }
    }
    cout << sum << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}