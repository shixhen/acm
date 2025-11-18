#include <bits/stdc++.h>

using namespace std;

struct dsu {
    int n;
    vector<int> f;
    vector<int> h;    // 树的高度
    dsu() {}
    dsu(int x): n(x) {
        f.resize(n + 1);
        h.resize(n + 1);
    }
    void init() {
        for (int i = 1; i <= n; i++) f[i] = i;
    }

    // 查找
    int find_set(int x) {
        // 递归写法：
        // return f[x] == x ? x : f[x] = find_set(f[x]);
        // 非递归写法：
        int r = x;
        while (f[r] != r) r = f[r];     // 找到根节点
        int i = x, j;       
        while(i != r) {                 // 路径压缩
            j = f[i];
            f[i] = r;
            i = j;
        }
        return r;
    }
    
    // 合并
    void merge(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (h[x] == h[y]) {             // 树的高度加一
            h[x] = h[y] + 1;             
            f[y] = x;
        } else {                        // 矮的的树合并到高的树，高度不变
            if (h[x] < h[y]) f[x] = y;
            else f[y] = x;
        }
    }

    // 判断是否为同一个根
    bool check(int x, int y) {
        return find_set(x) == find_set(y);
    }

    // 分组
    vector<vector<int>> groups() {
        vector<vector<int>> g;
        vector<int> temp;
        vector<bool> vis(n + 1);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            temp.push_back(i);
            int r = find_set(i);
            for (int j = i + 1; j <= n; j++) {
                if (vis[i]) continue;
                if (r == find_set(j)) {
                    temp.push_back(j);
                    vis[j] = true;
                }
            }
            g.push_back(temp);
            temp.clear();
        }
        return g;
    }
};

struct E {
    int u, v, w;
} e[100005];

bool cmp(E x, E y) {
    return x.w > y.w;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    vector<int> b(n + 1);
    ds.init();
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m + 1; i++) {
        if (ds.check(e[i].u, e[i].v)) {
            cout << e[i].w;
            return 0;
        }
        if (!b[e[i].u]) b[e[i].u] = e[i].v;
        else ds.merge(b[e[i].u], e[i].v);
        if (!b[e[i].v]) b[e[i].v] = e[i].u;
        else ds.merge(b[e[i].v], e[i].u);
    }
    return 0;
}