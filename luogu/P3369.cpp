#include <bits/stdc++.h>

using namespace std;

struct FHQTreap {
    struct Node {
        int l, r;
        int val;
        uint32_t pri;
        int cnt;
        int siz;
    };

    static const int MAXN = 200000 + 5;
    Node tr[MAXN];
    int root = 0;
    int tot = 0;
    mt19937 rng{static_cast<uint32_t>(chrono::steady_clock::now().time_since_epoch().count())};

    int node_size(int p) const {
        return p ? tr[p].siz : 0;
    }

    void pull(int p) {
        tr[p].siz = node_size(tr[p].l) + node_size(tr[p].r) + tr[p].cnt;
    }

    int new_node(int val) {
        ++tot;
        tr[tot] = {0, 0, val, rng(), 1, 1};
        return tot;
    }

    // Split into x(<val) and y(>=val).
    void split_less(int p, int val, int &x, int &y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (tr[p].val < val) {
            x = p;
            split_less(tr[p].r, val, tr[p].r, y);
            pull(x);
        } else {
            y = p;
            split_less(tr[p].l, val, x, tr[p].l);
            pull(y);
        }
    }

    // Split into x(<=val) and y(>val).
    void split_leq(int p, int val, int &x, int &y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (tr[p].val <= val) {
            x = p;
            split_leq(tr[p].r, val, tr[p].r, y);
            pull(x);
        } else {
            y = p;
            split_leq(tr[p].l, val, x, tr[p].l);
            pull(y);
        }
    }

    int merge(int x, int y) {
        if (!x || !y) {
            return x ? x : y;
        }
        if (tr[x].pri < tr[y].pri) {
            tr[x].r = merge(tr[x].r, y);
            pull(x);
            return x;
        }
        tr[y].l = merge(x, tr[y].l);
        pull(y);
        return y;
    }

    void insert(int val) {
        int a, b, c;
        split_less(root, val, a, c);
        split_leq(c, val, b, c);
        if (b) {
            tr[b].cnt++;
            pull(b);
        } else {
            b = new_node(val);
        }
        root = merge(a, merge(b, c));
    }

    void erase_one(int val) {
        int a, b, c;
        split_less(root, val, a, c);
        split_leq(c, val, b, c);
        if (b) {
            if (tr[b].cnt > 1) {
                tr[b].cnt--;
                pull(b);
            } else {
                b = merge(tr[b].l, tr[b].r);
            }
        }
        root = merge(a, merge(b, c));
    }

    // Number of elements less than val, then +1.
    int rank_of(int val) {
        int a, b;
        split_less(root, val, a, b);
        int ans = node_size(a) + 1;
        root = merge(a, b);
        return ans;
    }

    int kth(int p, int k) const {
        if (!p) {
            return -1;
        }
        if (k <= node_size(tr[p].l)) {
            return kth(tr[p].l, k);
        }
        if (k <= node_size(tr[p].l) + tr[p].cnt) {
            return tr[p].val;
        }
        return kth(tr[p].r, k - node_size(tr[p].l) - tr[p].cnt);
    }

    int kth(int k) const {
        return kth(root, k);
    }

    int predecessor(int val) {
        int a, b;
        split_less(root, val, a, b);
        int p = a;
        while (tr[p].r) {
            p = tr[p].r;
        }
        int ans = tr[p].val;
        root = merge(a, b);
        return ans;
    }

    int successor(int val) {
        int a, b;
        split_leq(root, val, a, b);
        int p = b;
        while (tr[p].l) {
            p = tr[p].l;
        }
        int ans = tr[p].val;
        root = merge(a, b);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    static FHQTreap t;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            t.insert(x);
        } else if (opt == 2) {
            t.erase_one(x);
        } else if (opt == 3) {
            cout << t.rank_of(x) << '\n';
        } else if (opt == 4) {
            cout << t.kth(x) << '\n';
        } else if (opt == 5) {
            cout << t.predecessor(x) << '\n';
        } else {
            cout << t.successor(x) << '\n';
        }
    }
}