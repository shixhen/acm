#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll rt, ct, ra, ca;
ll n, m, l;
vector<pair<char, long long>> s;
vector<pair<char, long long>> t;
ll cnt;

inline ll dis(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

ll temp;

ll p1, p2;

inline ll move1(ll k) {
    if (k == 0) return 0;
    ll k2 = k;
    while (k) {
        temp = min(s[p1].second, k);
        if (s[p1].first == 'R') {
            ct += temp;
            
        } else if (s[p1].first == 'L') {
            ct -= temp;
        } else if (s[p1].first == 'U') {
            rt -= temp;
        } else {
            rt += temp;
        }
        s[p1].second -= temp;
        k -= temp;
        if (s[p1].second == 0) p1++;
        if (k == 0) break;
    }
    while (k2) {
        temp = min(t[p2].second, k2);
        if (t[p2].first == 'R') {
            ca += temp;
            
        } else if (t[p2].first == 'L') {
            ca -= temp;
        } else if (t[p2].first == 'U') {
            ra -= temp;
        } else {
            ra += temp;
        }
        t[p2].second -= temp;
        k2 -= temp;
        if (t[p2].second == 0) p2++;
        if (k2 == 0) break;
    }
    if (rt == ra && ct == ca) return 1ll;
    return 0ll;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> rt >> ct >> ra >> ca;
    cin >> n >> m >> l;
    if (dis(rt, ct, ra, ca) % 2) {
        cout << 0;
        return 0;
    }
    s.resize(m + 2);
    t.resize(l + 2);
    for (int i = 0; i < m; i++) {
        cin >> s[i].first >> s[i].second;
    }
    for (int i = 0; i < l; i++) {
        cin >> t[i].first >> t[i].second;
    }
    ll ans = 0;
    ll tt, tt2;
    while (cnt != n) {
        tt2 = dis(rt, ct, ra, ca);
        if (tt2 == 0) {
            if (s[p1].first == t[p2].first) {
                tt = min(s[p1].second, t[p2].second);
                ans += tt;
                cnt += tt;
                move1(tt);
            } else {
                tt = min(2ll, n - cnt);
                ans += move1(tt);
                cnt += tt;
            }
        } else if (rt != ra && ct != ca && s[p1].first == t[p2].first) {
            tt = min(s[p1].second, t[p2].second);
            ans += move1(tt);
            cnt += tt;
        } else {
            tt = min(n - cnt, (tt2 + 1) / 2);
            ans += move1(tt);
            cnt += tt;
        }
        if (cnt >= n) break;
    }
    cout << ans << "\n";
    return 0;
}