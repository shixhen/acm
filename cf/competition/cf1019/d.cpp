#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    for (auto &i: a) {
        cin >> i;
    }
    int f = 0;
    int num = n;
    int st = 1;
    int last;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) last = i;
    }
    while (1) {
        int cnt = 0;
        f = 1 - f;
        for (int i = 0; i < n; i++) {
            a[i] -= 1;
            if (a[i] == 0) {
                cnt++;
            }
        }
        if (f % 2) {
            for (int i = 0; i < last; i++) {
                if (a[i] == 0) ans[i] = num--;
            }
            for (int i = n - 1; i > last; i--) {
                if (a[i] == 0) ans[i] = num--;
            }
        } else {
            for (int i = 0; i < last; i++) {
                if (a[i] == 0) ans[i] = st++;
            }
            for (int i = n - 1; i > last; i--) {
                if (a[i] == 0) ans[i] = st++;
            }
        }
        if (cnt == 0) {
            for (int i = 0; i < n; i++) {
                if (ans[i] == 0) ans[i] = num;
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}