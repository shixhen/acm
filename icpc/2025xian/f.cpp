#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;
constexpr int inf = 2e9 + 5;
int t[N], a[N], p[N], e[N];

int dir(int x) {
    return a[t[x]] > a[x] ? 1 : 0;
}

int dfs(int x) {
    if (e[x] != inf) {
        return e[x];
    }
    if (dir(x) != dir(t[x])) {
        e[x] = a[t[x]];
        return e[x];
    } else {
        e[x] = dfs(t[x]);
        return e[x];
    }
}

int dfs2(int x) {
    if (p[x] != inf) {
        return p[x];
    }
    if (dir(x) != dir(t[x])) {
        int tar = dfs2(t[x]);
        int mid = (a[x] + a[t[x]]) >> 1;
        if (abs(tar - a[t[x]]) <= abs(mid - a[t[x]])) {
            p[x] = tar;
        } else {
            p[x] = mid;
        }
        return p[x];
    } else {
        p[x] = dfs2(t[x]);
        return p[x];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        p[i] = inf;
        e[i] = inf;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] <<= 1;
    }
    for (int i = 1; i <= n; i++) {
        if (e[i] == inf) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dir(t[i]) < dir(i) && e[t[i]] <= a[i]) {
            p[i] = (a[i] + a[t[i]]) >> 1;
        } else if (dir(t[i]) > dir(i) && e[t[i]] >= a[i]) {
            p[i] = (a[i] + a[t[i]]) >> 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == inf) {
            dfs2(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << abs(p[i] - a[i]) << " \n"[i == n];
    }
    return 0;
}