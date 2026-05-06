#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct Node {
    int l, r;
    int val;
    int key;   // 随机优先级
    int sz;
    bool rev;
} tr[MAXN];

int root = 0, idx = 0;

int get_size(int x) {
    return x ? tr[x].sz : 0;
}

void pushup(int x) {
    tr[x].sz = get_size(tr[x].l) + get_size(tr[x].r) + 1;
}

void pushdown(int x) {
    if (!x || !tr[x].rev) return;
    swap(tr[x].l, tr[x].r);
    if (tr[x].l) tr[tr[x].l].rev ^= 1;
    if (tr[x].r) tr[tr[x].r].rev ^= 1;
    tr[x].rev = false;
}

int new_node(int val) {
    ++idx;
    tr[idx].val = val;
    tr[idx].key = rand();
    tr[idx].sz = 1;
    tr[idx].rev = false;
    tr[idx].l = tr[idx].r = 0;
    return idx;
}

// 按前 k 个节点分裂
void split(int now, int k, int &x, int &y) {
    if (!now) {
        x = y = 0;
        return;
    }
    pushdown(now);
    if (get_size(tr[now].l) >= k) {
        y = now;
        split(tr[now].l, k, x, tr[now].l);
        pushup(y);
    } else {
        x = now;
        split(tr[now].r, k - get_size(tr[now].l) - 1, tr[now].r, y);
        pushup(x);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].key < tr[y].key) {
        pushdown(x);
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

void inorder(int x) {
    if (!x) return;
    pushdown(x);
    inorder(tr[x].l);
    cout << tr[x].val << ' ';
    inorder(tr[x].r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        root = merge(root, new_node(i));
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        int a, b, c;
        split(root, r, a, c);        // a: 前 r 个
        split(a, l - 1, a, b);       // b: [l, r]
        tr[b].rev ^= 1;              // 翻转区间
        root = merge(merge(a, b), c);
    }

    inorder(root);
    return 0;
}
