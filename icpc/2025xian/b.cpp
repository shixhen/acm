#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l = 1, r = n;
    vector<int> cc(n + 1);
    vector<int> cw(n + 1);
    vector<int> cp(n + 1);
    s = " " + s + " ";
    for (int i = 1; i <= n; i++) {
        cc[i] = cc[i - 1];
        cw[i] = cw[i - 1];
        cp[i] = cp[i - 1];
        if (s[i] == 'C') {
            cc[i]++;
        } else if (s[i] == 'W') {
            cw[i]++;
        } else {
            cp[i]++;
        }
    }
    if (cc[n] + cw[n] + cp[n] - max({cc[n], cw[n], cp[n]}) + 1 < max({cc[n], cw[n], cp[n]})) {
        cout << "Impossible\n";
        return;
    }
    for (; l < r; l++) {
        if (s[l] == s[l + 1]) {
            break;
        }
    }
    if (l == r) {
        cout << "Beautiful\n";
        return;
    }
    
    for (; r > l; r--) {
        if (s[r] == s[r - 1]) {
            break;
        }
    }
    l++;
    r--;
    //cout << l << ' ' << r << " ----\n";
    int st, ed;
    auto check = [&] (int len) -> bool {
        int b = max(len, r);
        for (; b <= n && b - len + 1 <= l; b++) {
            int ccnt = cc[b] - cc[b - len];
            int wcnt = cw[b] - cw[b - len];
            int pcnt = cp[b] - cp[b - len];
            int sum = ccnt + wcnt + pcnt;
            int maxn = max({ccnt, wcnt, pcnt});
            if (sum - maxn + 1 < maxn) {
                continue;
            }
            // 判断左侧边界
            ccnt += s[b - len] == 'C';
            wcnt += s[b - len] == 'W';
            pcnt += s[b - len] == 'P';
            sum = ccnt + wcnt + pcnt;
            maxn = max({ccnt, wcnt, pcnt});
            if (sum - maxn + 1 < maxn) {
                continue;
            }
            // 判断两侧
            ccnt += s[b + 1] == 'C';
            wcnt += s[b + 1] == 'W';
            pcnt += s[b + 1] == 'P';
            sum = ccnt + wcnt + pcnt;
            maxn = max({ccnt, wcnt, pcnt});
            if (sum - maxn + 1 < maxn) {
                continue;
            }
            // 判断右侧
            ccnt -= s[b - len] == 'C';
            wcnt -= s[b - len] == 'W';
            pcnt -= s[b - len] == 'P';
            sum = ccnt + wcnt + pcnt;
            maxn = max({ccnt, wcnt, pcnt});
            if (sum - maxn + 1 < maxn) {
                continue;
            }            
            st = b - len + 1;
            ed = b;
            return true;
        }
        return false;
    };
    int ll = max(2, r - l + 1), rr = n;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (check(mid)) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }
    if (ll == rr) {
        check(ll);
    }
    cout << "Possible\n";
    cout << st << ' ' << ed << '\n';
    int ccnt = cc[ed] - cc[st - 1];
    int wcnt = cw[ed] - cw[st - 1];
    int pcnt = cp[ed] - cp[st - 1];
    l = st, r = ed;
    string ans = " ";
    for (int i = 1; i < st; i++) {
        ans += s[i];
    }
    for (int i = st; i <= ed; i++) {
        ans += ' ';
    }
    for (int i = ed + 1; i <= n; i++) {
        ans += s[i];
    }
    ans += ' ';
    auto maxc = [&] (int c, int w, int p) -> char {
        int maxn = max({c, w, p});
        if (maxn == c && c == w) {
            if (ans[r + 1] == 'W') {
                wcnt--;
                return 'W';
            } else {
                ccnt--;
                return 'C';
            }
        }
        if (maxn == w && w == p) {
            if (ans[r + 1] == 'P') {
                pcnt--;
                return 'P';
            } else {
                wcnt--;
                return 'W';
            }
        }
        if (maxn == c && c == p) {
            if (ans[r + 1] == 'P') {
                pcnt--;
                return 'P';
            } else {
                ccnt--;
                return 'C';
            }
        }
        if (maxn == c) {
            ccnt--;
            return 'C';
        } else if (maxn == w) {
            wcnt--;
            return 'W';
        } else {
            pcnt--;
            return 'P';
        }
    };
    while (l <= r) {
        int sc = ccnt, sw = wcnt, sp = pcnt;
        int maxn = max({sc, sw, sp});
        int sum = sc + sw + sp;
        if (sum - maxn + 1 == maxn) {
            char ch = maxc(sc, sw, sp);
            ans[l] = ch;
            l++;
            continue;
        }
        if (ans[l - 1] == 'C') {
            sc = 0;
        } else if (ans[l - 1] == 'W') {
            sw = 0;
        } else if (ans[l - 1] == 'P') {
            sp = 0;
        }
        char ch = maxc(sc, sw, sp);
        ans[l] = ch;
        l++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}