#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 100005;

ll a[N];
queue<ll> q1, q2;

inline void read(ll &x) {
    x = 0;
    int f = 0;
    char ch = 0;
    while(!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    x = f ? -x : x;
}

inline ll get() {
    ll x;
    if (q2.empty() || (!q1.empty() && q2.front() >= q1.front())) {
        x = q1.front();
        q1.pop();
    } else {
        x = q2.front();
        q2.pop();
    }
    return x;
}

int main() {
    ll n;
    read(n);
    ll x, y;
    for (int i = 1; i <= n; i++) {
        read(x);
        a[x]++;
    }
    for (int i = 1; i <= 100000; i++) {
        while (a[i]--) {
            q1.push(i);
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        x = get();
        y = get();
        ans += x + y;
        q2.push(x + y);
    }
    cout << ans;
    return 0;
}


