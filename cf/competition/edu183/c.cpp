#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnta = 0, cntb = 0;
    for (auto &c : s) {
        if (c == 'a') cnta++;
        else cntb++;
    }
    if (cnta == cntb) {
        cout << 0 << "\n";
        return;
    }
    int ta = 0;
    int tb = 0;
    int la = 0, lb = 0;
    int minn = n;
    int l = 0, r = 0;
    vector<int> bb(n + 1);
    vector<int> aa(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            ta++;
            tb--;
            aa[ta] = i;
        } else {
            ta--;
            tb++;
            bb[tb] = i;
        }
        if (ta <= 0) {
            ta = 0;
        }
        if (tb <= 0) {
            tb = 0;
        }
        //cout << i << " " << tb << "\n";
        if (cnta > cntb) {
            if (ta >= cnta - cntb) {
                minn = min(minn, i - aa[ta - (cnta - cntb) + 1] + 1);
            }
        } else {
            if (tb >= cntb - cnta) {
                minn = min(minn, i - bb[tb - (cntb - cnta) + 1] + 1);
            }
        }
    }
    if (minn == n) minn = -1;
    cout << minn << "\n";
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