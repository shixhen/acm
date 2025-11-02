#include <bits/stdc++.h>

using namespace std;

int ask(int h, int p) {
    cout << "? " << h << " " << p << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int x = 1, res;
    vector<int> ans(n + 2);
    while (x <= n) {
        res = ask(1000000000, x);
        ans[res] = 2;
        x = res + 1;
    }
    x = 1;
    while (x <= n) {
        while (ans[x] == 2) x++;
        if (x > n) break;
        res = ask(1, x);
        if (ans[res] == 0) ans[res] = 1;
        x = res + 1;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    cout.flush();
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