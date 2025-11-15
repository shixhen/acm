#include <bits/stdc++.h>

using namespace std;

struct node {
    int v;
    int idx;
};

vector<node> a;

node win(int l, int r) {
    if (l == r) return a[l];
    node ll = win(l, (l + r) >> 1);
    node rr = win((l + r + 1) >> 1, r);
    if (ll.v < rr.v) {
        return rr;
    } else return ll;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    a.resize((1 << n) + 1);
    for (int i = 1; i <= (1 << n); i++) {
        cin >> a[i].v;
        a[i].idx = i;
    }
    node ll = win(1, (1 << n) >> 1);
    node rr = win(((1 << n) >> 1) + 1, (1 << n));
    if (ll.v < rr.v) {
        cout << ll.idx;
    } else cout << rr.idx;
    return 0;
}