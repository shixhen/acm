#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;

struct Node {
    int key;        // 键值
    int pri;        // 随机优先级
    int cnt;        // 当前 key 出现次数
    int sz;         // 子树大小（含重复）
    int l, r;
} tr[N];

int root = 0, tot = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int newNode(int key) {
    ++tot;
    tr[tot].key = key;
    tr[tot].pri = rng();
    tr[tot].cnt = 1;
    tr[tot].sz = 1;
    tr[tot].l = tr[tot].r = 0;
    return tot;
}

int getSize(int p) {
    return p ? tr[p].sz : 0;
}

void pushUp(int p) {
    tr[p].sz = getSize(tr[p].l) + getSize(tr[p].r) + tr[p].cnt;
}

/* 右旋 */
void rotateRight(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    pushUp(p);
    pushUp(q);
    p = q;
}

/* 左旋 */
void rotateLeft(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    pushUp(p);
    pushUp(q);
    p = q;
}

/* 插入 */
void insert(int &p, int key) {
    if (!p) {
        p = newNode(key);
        return;
    }
    if (key == tr[p].key) {
        tr[p].cnt++;
    } else if (key < tr[p].key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].pri > tr[p].pri)
            rotateRight(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].pri > tr[p].pri)
            rotateLeft(p);
    }
    pushUp(p);
}

/* 删除 */
void erase(int &p, int key) {
    if (!p) return;
    if (key == tr[p].key) {
        if (tr[p].cnt > 1) {
            tr[p].cnt--;
        } else {
            if (!tr[p].l || !tr[p].r) {
                p = tr[p].l ? tr[p].l : tr[p].r;
                return;
            } else if (tr[tr[p].l].pri > tr[tr[p].r].pri) {
                rotateRight(p);
                erase(tr[p].r, key);
            } else {
                rotateLeft(p);
                erase(tr[p].l, key);
            }
        }
    } else if (key < tr[p].key) {
        erase(tr[p].l, key);
    } else {
        erase(tr[p].r, key);
    }
    if (p) pushUp(p);
}

/* 查找 */
bool find(int p, int key) {
    while (p) {
        if (key == tr[p].key) return true;
        if (key < tr[p].key) p = tr[p].l;
        else p = tr[p].r;
    }
    return false;
}

/* 中序遍历（调试用） */
void inorder(int p) {
    if (!p) return;
    inorder(tr[p].l);
    for (int i = 0; i < tr[p].cnt; i++)
        cout << tr[p].key << ' ';
    inorder(tr[p].r);
}
