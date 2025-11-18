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
            if (h[x] < h[y]) {
                f[x] = y;
                h[y] += h[x];
            } else {
                f[y] = x;
            }
        }
    }

    // 判断是否为同一个根
    bool check(int x, int y) {
        return find_set(x) == find_set(y);
    }

    // 分组
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    return 0;
}