#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n;
    string s, h;
    cin >> s;
    vector<int> a;
    h.push_back('@');
    h.push_back('#');
    a.push_back(-2);
    a.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w') {
            a.push_back(i);
            a.push_back(i);
            a.push_back(i);
            a.push_back(i);
            h.push_back('v');
            h.push_back('!');
            h.push_back('v');
            h.push_back('#');
        } else {
            a.push_back(i);
            a.push_back(i);
            h.push_back(s[i]);
            h.push_back('#');
        }
    }
    h.push_back('$');
    a.push_back(0);
    m = h.size();
    int c, r = 0;
    int ans = 0;
    vector<int> b(m + 1);
    int maxlen = 0;
    for (int i = 1; i < m; i++) {
        if (i < r) b[i] = min(b[2 * c - i], b[c] + c - i);
        else b[i] = 1;
        while (1) {
            if (h[i + b[i] - 1] == h[i - b[i] + 1] && h[i + b[i] - 1] != '!' && h[i - b[i] + 1] != '!' && h[i - b[i]] != '!' && h[i + b[i]] != '!') {
                int l = a[i - b[i] + 1];
                int lr = a[i + b[i] - 1];
                if (h[i - b[i] + 1] == '#') l++;
                if (lr - l + 1 > maxlen) {
                    maxlen = lr - l + 1;
                    ans = l;
                }
            }
            if (h[i + b[i]] == h[i - b[i]] && h[i - b[i] != '!']) {
                if (h[i + b[i] + 1] != '!' && h[i - b[i] - 1] != '!') {
                    int l = a[i - b[i]];
                    int lr = a[i + b[i]];
                    if (h[i - b[i]] == '#') l++;

                    if (lr - l + 1 > maxlen) {
                        maxlen = lr - l + 1;
                        ans = l;
                    }
                }
            } else if (h[i + b[i]] == '!' || h[i - b[i]] == '!') {
            } else break;
            ++b[i];
        }
        if (b[i] + i > r) {
            r = b[i] + i;
            c = i;
        }
    }
    //cout << maxlen << endl;
    for (int i = ans; i < ans + maxlen; i++) {
        cout << s[i];
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}