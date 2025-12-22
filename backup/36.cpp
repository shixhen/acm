#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 5;

// 节点
struct Node {
    int val;
    int l;
    int r;
} tr[N];

Node f_stk[N];

int root = 0, tot = 0, top = 0;

int newNode(int x) {
    if (top) {
        tr[f_stk[--top].val] = {x, 0, 0};
        return f_stk[top].val;
    }

    tr[++tot] = {x, 0, 0};
    return tot;
}

void insert(int x) {
    if (!root) {
        root = newNode(x);
        return;
    }

    int cur = root, fa = 0;
    while (cur) {
        fa = cur;
        if (x < tr[cur].val) cur = tr[cur].l;
        else if (x > tr[cur].val) cur = tr[cur].r;
        else return;
    }
    if (x < tr[fa].val) tr[fa].l = newNode(x);
    else tr[fa].r = newNode(x);
}

bool find(int x) {
    int cur = root;
    while (cur) {
        if (x == tr[cur].val) return true;
        if (x < tr[cur].val) cur = tr[cur].l;
        else cur = tr[cur].r;
    }
    return false;
}

void erase(int x) {
    int cur = root, fa = 0;
    while (cur && tr[cur].val != x) {
        fa = cur;
        if (x < tr[cur].val) cur = tr[cur].l;
        else cur = tr[cur].r;
    }

    // 未找到
    if (!cur) return;

    if (tr[cur].l && tr[cur].r) {
        int p = cur, s = tr[cur].r;
        // 寻找右子树的最小值
        while (tr[s].l) {
            p = s;
            s = tr[s].l;
        }
        // 用该最小值覆盖当前节点
        tr[cur].val = tr[s].val;
        cur = s;
        fa = p;
    }

    int child = tr[cur].l ? tr[cur].l : tr[cur].r;

    if (!fa) root = child;
    else {
        if (tr[fa].l == cur) tr[fa].l = child;
        else tr[fa].r = child;
    }

    // 回收节点
    f_stk[top++].val = cur;
}

// 中序遍历
void inorder(int u) {
    if (!u) return;
    inorder(tr[u].l);
    cout << tr[u].val << " ";
    inorder(tr[u].r);
}

void solve() {
    root = 0;
    tot = 0;
    top = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
    }
    inorder(root);
    cout << "\n";
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        erase(x);
        inorder(root);
        cout << "\n";
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}