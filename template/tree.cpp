#include <bits/stdc++.h>

using namespace std;

// 因为范围太大，所以用树状数组实现单点修改，区间查询
int lowbit(int x) {
    return x & -x;
}

// 更新区间最大值
void updatemax(int x, long long val, int n, vector<long long>& t) {
    // 确保所有节点都会更新
    while (x <= n) {
        if (val > t[x]) t[x] = val;
        else break;                  // 如果当前节点更大，则停止更新
        x += lowbit(x);              // 更新下一个父节点
    }
    return;
}

// 查询区间最大值
long long querymax(int l, int r, vector<long long> &t, vector<long long>& a) {
    long long ans = -0x7f7f7f7f7f7f7f7f;
    while (r >= l) {
        if (r - lowbit(r) + 1 >= l && r != 0) {     // 由于这里l可以等于零，所以加了个特判不能等于零，防止死循环
            ans = max(ans, t[r]);
            r -= lowbit(r);
        } else {                                    // 若当前节点覆盖范围已超出查询范围，则查询原始数组
            ans = max(ans, a[r]);
            r--;
        }
    }
    return ans;
}