#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 200005;

int a[N << 1], tot;
ll v[N << 3], w[N << 3];




struct Line {
    ll x1, x2, y, o;

} b[N << 1];

struct cmp {
    bool operator()(Line a, Line b) {
        return a.y < b.y || (a.y == b.y && a.o < b.o);
    }
};

int f(int y) {
    return lower_bound(a, a + tot, y) - a;
}

void up(int u, int l, int r) {
    if (v[u]) w[u] = a[r] - a[l];
    else if (l + 1 == r) w[u] = 0;
    else w[u] = w[u * 2 + 1] + w[u * 2 + 2];
}

void add(int x1, int x2, ll o, int u = 0, int l = 0, int r = tot - 1) {
    if (x1 == l && x2 == r) {
        v[u] += o;
        up(u, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (x1 < mid) {
        add(x1, min(x2, mid), o, u * 2 + 1, l, mid);
    }
    if (mid < x2) {
        add(max(x1, mid), x2, o, u * 2 + 2, mid, r);
    }
    up(u, l, r);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int x1, x2, y1, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        b[i] = {x1, x2, y1, 1};
        b[i + n] = {x1, x2, y2, -1};
        a[i] = x1;
        a[i + n] = x2;
    }
    sort(a, a + 2 * n);
    tot = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (a[i] != a[tot - 1]) {
            a[tot++] = a[i];
        }
    }
    sort(b, b + 2 * n, [](Line a, Line b) {
        return a.y < b.y || (a.y == b.y && a.o < b.o);
    });
    ll sum = 0;
    add(f(b[0].x1), f(b[0].x2), 1);
    for (int i = 1; i < n * 2; i++) {
        x1 = f(b[i].x1);
        x2 = f(b[i].x2);
        sum += (b[i].y - b[i - 1].y) * w[0];
        add(x1, x2, b[i].o);
    }
    cout << sum << "\n";
    return 0;
}