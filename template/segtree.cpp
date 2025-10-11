#include <bits/stdc++.h>

using namespace std;

// 带懒标记的线段树 - 支持区间乘法和区间加法
constexpr int N = 1e5 + 10;
long long mod;
long long a[N];
long long node[N << 2];  // 存储区间和
long long mul_lazy[N << 2];  // 乘法懒标记
long long add_lazy[N << 2];  // 加法懒标记

// 向下推送懒标记
void pushdown(int l, int r, int idx) {
    if (mul_lazy[idx] != 1 || add_lazy[idx] != 0) {
        int mid = (l + r) >> 1;
        
        // 更新左子树
        node[idx << 1] = (node[idx << 1] * mul_lazy[idx] + add_lazy[idx] * (mid - l + 1)) % mod;
        mul_lazy[idx << 1] = (mul_lazy[idx << 1] * mul_lazy[idx]) % mod;
        add_lazy[idx << 1] = (add_lazy[idx << 1] * mul_lazy[idx] + add_lazy[idx]) % mod;
        
        // 更新右子树
        node[idx << 1 | 1] = (node[idx << 1 | 1] * mul_lazy[idx] + add_lazy[idx] * (r - mid)) % mod;
        mul_lazy[idx << 1 | 1] = (mul_lazy[idx << 1 | 1] * mul_lazy[idx]) % mod;
        add_lazy[idx << 1 | 1] = (add_lazy[idx << 1 | 1] * mul_lazy[idx] + add_lazy[idx]) % mod;
        
        // 清除当前节点的懒标记
        mul_lazy[idx] = 1;
        add_lazy[idx] = 0;
    }
}

void build(int l, int r, int idx) {
    mul_lazy[idx] = 1;  // 初始化乘法懒标记为1
    add_lazy[idx] = 0;  // 初始化加法懒标记为0
    if (l == r) {
        node[idx] = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    node[idx] = (node[idx << 1] + node[idx << 1 | 1]) % mod;
}

// 区间乘法更新
void multiply_update(int l, int r, int idx, int x, int y, long long k) {
    if (l >= x && r <= y) {
        // 完全包含在更新区间内
        node[idx] = (node[idx] * k) % mod;
        mul_lazy[idx] = (mul_lazy[idx] * k) % mod;
        add_lazy[idx] = (add_lazy[idx] * k) % mod;
        return;
    }
    pushdown(l, r, idx);  // 先推送懒标记
    int mid = (l + r) >> 1;
    if (x <= mid) {
        multiply_update(l, mid, idx << 1, x, y, k);
    }
    if (y > mid) {
        multiply_update(mid + 1, r, idx << 1 | 1, x, y, k);
    }
    node[idx] = (node[idx << 1] + node[idx << 1 | 1]) % mod;
}

// 区间加法更新
void add_update(int l, int r, int idx, int x, int y, long long k) {
    if (l >= x && r <= y) {
        // 完全包含在更新区间内
        node[idx] = (node[idx] + k * (r - l + 1)) % mod;
        add_lazy[idx] = (add_lazy[idx] + k) % mod;
        return;
    }
    pushdown(l, r, idx);  // 先推送懒标记
    int mid = (l + r) >> 1;
    if (x <= mid) {
        add_update(l, mid, idx << 1, x, y, k);
    }
    if (y > mid) {
        add_update(mid + 1, r, idx << 1 | 1, x, y, k);
    }
    node[idx] = (node[idx << 1] + node[idx << 1 | 1]) % mod;
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
    return res % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q >> mod;
    
    // 读入初始数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 建树
    build(1, n, 1);
    
    // 处理操作
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        
        if (op == 1) {
            // 操作1：区间乘法：将区间[x,y]内每个数乘上k
            int x, y;
            long long k;
            cin >> x >> y >> k;
            multiply_update(1, n, 1, x, y, k);
        } else if (op == 2) {
            // 操作2：区间加法：将区间[x,y]内每个数加上k
            int x, y;
            long long k;
            cin >> x >> y >> k;
            add_update(1, n, 1, x, y, k);
        } else if (op == 3) {
            // 操作3：区间查询：查询区间[x,y]内每个数的和对m取模
            int x, y;
            cin >> x >> y;
            cout << query(1, n, 1, x, y) << "\n";
        }
    }
    
    return 0;
}