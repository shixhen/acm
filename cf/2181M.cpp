#include <bits/stdc++.h>

using namespace std;

void solve() {
    string x, y;
    cin >> x >> y;
    int n = (int)x.size();
    int cnt0 = 0, cnt1 = 0x3f3f3f3f;
    int t0 = 0, t1 = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            if (y[i] == '1') {
                // 1 1
                t0 = min(cnt1 + 1, cnt0 + 2);
                t1 = min(cnt0, cnt1 + 1);
            } else {
                // 1 0
                t1 = min(cnt0 + 1, cnt1 + 2);
                t0 = min(cnt1, cnt0 + 1);
            }
        } else {
            if (y[i] == '1') {
                // 0 1
                t0 = min(cnt0 + 1, cnt1 + 2);
                t1 = min(cnt1, cnt0 + 1);
            } else {
                // 0 0
                t1 = min(cnt1 + 1, cnt0 + 2);
                t0 = min(cnt0, cnt1 + 1);
            }
        }
        cnt0 = t0;
        cnt1 = t1;
        //cout << "i=" << i << " cnt0=" << cnt0 << " cnt1=" << cnt1 << "\n";
    }
    cout << min(cnt0, cnt1) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}