#include <bits/stdc++.h>

using namespace std;

int ask(int i, int x) {
    cout << "? " << i << " " << x << endl;
    int res;
    cin >> res;
    return res;
}

int bitwidth(int x) {
    if (x == 0) return 0;
    return 32 - __builtin_clz(x);
}

void solve() {
    int n;
    cin >> n;
    int nn = n;
    int w = bitwidth(n);
    vector<int> vis(n + 1);
    int ans = 0;
    for (int i = w; i >= 1; i--) {
        int t = (1 << (bitwidth(n) - 1)) - 1;
        int x = t + 1;
        int cnt1 = 0, cnt0 = 0;
        vector<int> temp(nn + 1);
        for (int j = 1; j < nn; j++) {
            if (vis[j]) continue;
            int res = ask(j, x);
            if (res == 1) cnt1++;
            else cnt0++;
            if (res == 1) {
                temp[j] = 2;
            } else {
                temp[j] = 1;
            }
            if (cnt0 == t || cnt1 == n - t) break;
        }
        if (cnt0 == t) {
            for (int j = 1; j < nn; j++) {
                if (temp[j] == 1) {
                    vis[j] = 1;
                }
            }
            n -= t;
            ans |= (1 << (i - 1));
        } else {
            for (int j = 1; j < nn; j++) {
                if (temp[j] == 2) {
                    vis[j] = 1;
                }
            }
            n = t;
        }
        if (n == 2 || n == 1) break;
    }
    if (n == 2) {
        for (int i = 1; i < nn; i++) {
            if (!vis[i]) {
                int res = ask(i, 1);
                if (res == 0) {
                    ans |= 1;
                }
                break;
            }
        }
    }
    
    cout << "! " << ans << endl;
    return;
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
