#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> ls, rs;
int p;

void build() {
    p++;
    if (s[p] == '#') {
        return;
    }
    int u = p;
    ls[u] = p + 1;
    build();
    rs[u] = p + 1;
    build();
}

void dfs1(int u) {
    if (s[u] == '#') {
        return;
    }
    cout << s[u] << ' ';
    dfs1(ls[u]);
    dfs1(rs[u]);
}

void dfs2(int u) {
    if (s[u] == '#') {
        return;
    }
    dfs2(ls[u]);
    cout << s[u] << ' ';
    dfs2(rs[u]);
}

void dfs3(int u) {
    if (s[u] == '#') {
        return;
    }
    dfs3(ls[u]);
    dfs3(rs[u]);
    cout << s[u] << ' ';
}

void solve() {
    cin >> s;
    if (s[0] == '#') {
        cout << "NULL\nNULL\nNULL\nNULL\n";
        return;
    }
    int n = (int) s.size() + 1;
    ls.assign(n, 0);
    rs.assign(n, 0);
    p = -1;
    build();
    for (int i = 0; i < n; i++) {
        swap(ls[i], rs[i]);
    }
    dfs1(0);
    cout << '\n';
    dfs2(0);
    cout << '\n';
    dfs3(0);
    cout << '\n';
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (s[u] == '#') {
            continue;
        }
        cout << s[u] << ' ';
        q.push(ls[u]);
        q.push(rs[u]);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}