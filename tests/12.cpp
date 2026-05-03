#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
struct node2{
    ll b, r;
    int p;
}a[N];

struct node{
    ll r;
    int p;
}val[N];
bool operator<(const node& a, const node& b) {
    if (a.r != b.r) return a.r > b.r;
    return a.p < b.p;
}
int sz[N], dat[N], ls[N], rs[N], rt, rcnt;
int New(const node& v) {
    val[++rcnt] = v;
    sz[rcnt] = 1;
    dat[rcnt] = rand();
    return rcnt;
}
void pu(int u) {
    sz[u] = sz[ls[u]] + sz[rs[u]] + 1;
}
void split(int u, const node& x, int& l, int& r) {
    if(!u) return l = r = 0, void();
    if(x < val[u]) {
        r = u;
        split(ls[u], x, l, ls[u]);
    }else {
        l = u;
        split(rs[u], x, rs[u], r);
    }
    pu(u);
}
int merge(int l, int r) {
    if(!l || !r) return l + r;
    if(dat[l] > dat[r]) {
        rs[l] = merge(rs[l], r);
        pu(l);
        return l;
    }
    ls[r] = merge(l, ls[r]);
    pu(r);
    return r;
}
int kth(int u, int x) {
    if(x <= sz[ls[u]]) return kth(ls[u], x);
    if(x <= sz[ls[u]] + 1) return u;
    return kth(rs[u], x - sz[ls[u]] - 1);
}
void ins(int& u, const node& x) {
    int a, b; split(u, x, a, b);
    u = merge(merge(a, New(x)), b);
}

void solve() {
    int n, m;
    ll k;
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++) {
        cin>>a[i].b;
        a[i].r = a[i].b % k;
        if(a[i].r < 0) a[i].r += k;
        a[i].b = (a[i].b - a[i].r) / k;
        a[i].p = i;
    }
    sort(a, a + n, [](const node2& a, const node2& b) {
        if(a.b != b.b) return a.b > b.b;
        if(a.r != b.r) return a.r > b.r;
        return a.p < b.p;
    });

    char op;
    ll x, y;
    ins(rt, {a[0].r, a[0].p});
    for (int i = 1; i < n; i++) {
        if (a[i].b == a[0].b) {
            ins(rt, {a[i].r, a[i].p});
        } else {
            break;
        } 
    }

    while(m--) {
        int t;
        cin >> op >> x;
        if (op == 'A') {
            cin >> t;
            
        } else {
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}