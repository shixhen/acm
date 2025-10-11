#include <bits/stdc++.h>

using namespace std;

// 带懒标记的线段树
constexpr int N = 1e5 + 10;
long long a[N];
long long node[N << 2];  // 存储区间和
long long lazy[N << 2];  // 懒标记

// 向下推送懒标记
void pushdown(int l, int r, int idx) {
    if (lazy[idx] != 0) {
        int mid = (l + r) >> 1;
        // 更新左子树
        node[idx << 1] += lazy[idx] * (mid - l + 1);
        lazy[idx << 1] += lazy[idx];
        // 更新右子树
        node[idx << 1 | 1] += lazy[idx] * (r - mid);
        lazy[idx << 1 | 1] += lazy[idx];
        // 清除当前节点的懒标记
        lazy[idx] = 0;
    }
}

void build(int l, int r, int idx) {
    lazy[idx] = 0;  // 初始化懒标记
    if (l == r) {
        node[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    node[idx] = node[idx << 1] + node[idx << 1 | 1];
}

// 单点更新
void add(int l, int r, int idx, int x, long long v) {
    if (l == r) {
        node[idx] += v;
        return;
    }
    pushdown(l, r, idx);  // 先推送懒标记
    int mid = (l + r) >> 1;
    if (x <= mid) {
        add(l, mid, idx << 1, x, v);
    } else {
        add(mid + 1, r, idx << 1 | 1, x, v);
    }
    node[idx] = node[idx << 1] + node[idx << 1 | 1];
}

// 区间更新（给区间[x,y]的所有元素加上v）
void update(int l, int r, int idx, int x, int y, long long v) {
    if (l >= x && r <= y) {
        // 完全包含在更新区间内
        node[idx] += (long long)v * (r - l + 1);
        lazy[idx] += v;
        return;
    }
    pushdown(l, r, idx);  // 先推送懒标记
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(l, mid, idx << 1, x, y, v);
    }
    if (y > mid) {
        update(mid + 1, r, idx << 1 | 1, x, y, v);
    }
    node[idx] = node[idx << 1] + node[idx << 1 | 1];
}

// 区间查询
long long query(int l, int r, int idx, int x, int y) {
    if (l >= x && r <= y) {
        return node[idx];
    }
    pushdown(l, r, idx);  // 先推送懒标记
    int mid = (l + r) >> 1;
    long long res = 0;
    if (x <= mid) {
        res += query(l, mid, idx << 1, x, y);
    }
    if (y > mid) {
        res += query(mid + 1, r, idx << 1 | 1, x, y);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // 读入初始数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 建树
    build(1, n, 1);
    
    // 处理操作
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        
        if (op == 1) {
            // 区间更新：给区间[l,r]的所有元素加上k
            long long l, r, k;
            cin >> l >> r >> k;
            update(1, n, 1, l, r, k);
        } else if (op == 2) {
            // 区间查询：查询区间[l,r]的和
            long long l, r;
            cin >> l >> r;
            cout << query(1, n, 1, l, r) << "\n";
        }
    }
    return 0;
}