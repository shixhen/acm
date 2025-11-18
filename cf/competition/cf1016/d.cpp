#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(long long x, int d) {
    pair<int, int> p;
    long long t = (x - 1) % 4 + 1;
    x = (x - 1) / 4 + 1;
    if (t == 2) {
        p.first += 1 << d;
        p.second += 1 << d;
    } else if (t == 3) {
        p.first += 1 << d;
    } else if (t == 4) {
        p.second += 1 << d;
    }
    if (x > 1) {
        pair<int, int> temp = dfs(x, d + 1);
        p.first += temp.first;
        p.second += temp.second;
    }
    return p;
} 

long long qpow(long long a, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1)res *= a;
        a *= a;
        t >>= 1;
    }
    return res;
}

long long res(int x, int y, int d) {
    if (x == 0 && y == 0) return 0;
    long long temp = 0;
    if ((x & 1) and (y & 1)) {
        temp += qpow(4, (d - 1)) * 1;
    } else if (x & 1) {
        temp += qpow(4, (d - 1)) * 2;
    } else if (y & 1) {
        temp += qpow(4, (d - 1)) * 3;
    }
    return temp + res(x >> 1, y >> 1, d + 1);
}



void solve() {
    int n;
    int q;
    cin >> n >> q;
    string s;
    long long x, y, d;
    while (q--) {
        cin >> s;
        if (s == "->") {
            cin >> x >> y;
            cout << res(x - 1, y - 1, 1) + 1 << '\n';
        } else {
            cin >> d;
            pair<int, int> ans = dfs(d, 0);
            cout << ans.first + 1 << ' ' << ans.second + 1<< '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}