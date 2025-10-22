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
    s = " " + s;
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
    if (cc[n] + cw[n] + cp[n] - max({cc[n], cw[n], cp[n]}) + 1 >= max({cc[n], cw[n], cp[n]})) {
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
    if (l + 1 != r) {
        l++;
        r--;
    }
    int st, ed;
    auto check = [&] (int len) -> bool {
        int b = max(len, r);
        for (; b <= n && b - len + 1 <= l; b++) {
            int ccnt = cc[b] - cc[b - len];
            int wcnt = cw[b] - cw[b - len];
            int pcnt = cp[b] - cp[b - len];
            if (b - len > 0) {
                ccnt += s[b - len] == 'C';
                wcnt += s[b - len] == 'W';
                pcnt += s[b - len] == 'P';
            }
            if (b + 1 <= n) {
                ccnt += s[b + 1] == 'C';
                wcnt += s[b + 1] == 'W';
                pcnt += s[b + 1] == 'P';
            }
            int sum = ccnt + wcnt + pcnt;
            int maxn = max({ccnt, wcnt, pcnt});
            if (sum - maxn + 1 >= maxn) {
                st = b - len + 1;
                ed = b;
                return true;
            }
        }
        return false;
    };
    int ll = r - l + 1, rr = n;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (check(mid)) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }
    cout << "Possible\n";
    

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