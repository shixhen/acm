#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;

struct Node {
    int val, l, r;
} tr[N];

int root = 0, tot = 0;

int newNode(int x) {
    tr[++tot] = {x, 0, 0};
    return tot;
}

// 插入
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

// 查找
bool find(int x) {
    int cur = root;
    while (cur) {
        if (x == tr[cur].val) return true;
        if (x < tr[cur].val) cur = tr[cur].l;
        else cur = tr[cur].r;
    }
    return false;
}

// 删除
void erase(int x) {
    int cur = root, fa = 0;
    while (cur && tr[cur].val != x) {
        fa = cur;
        if (x < tr[cur].val) cur = tr[cur].l;
        else cur = tr[cur].r;
    }
    if (!cur) return;

    if (tr[cur].l && tr[cur].r) {
        int p = cur, s = tr[cur].r;
        while (tr[s].l) {
            p = s;
            s = tr[s].l;
        }
        tr[cur].val = tr[s].val;
        cur = s;
        fa = p;
    }

    int child = tr[cur].l ? tr[cur].l : tr[cur].r;

    if (!fa) root = child;
    else if (tr[fa].l == cur) tr[fa].l = child;
    else tr[fa].r = child;
}

// 中序
void inorder() {
    stack<int> st;
    int cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = tr[cur].l;
        }
        cur = st.top(); st.pop();
        cout << tr[cur].val << " ";
        cur = tr[cur].r;
    }
    cout << "\n";
}

int main() {
    insert(5);
    insert(3);
    insert(7);
    insert(2);
    insert(4);

    inorder();     // 2 3 4 5 7
    erase(3);
    inorder();     // 2 4 5 7
}
