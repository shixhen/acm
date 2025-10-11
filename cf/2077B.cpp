#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long q1 = 0, q2 = 0, a1, a2;
    vector<int> t(32, 1);
    for (int i = 1; i < 31; i++) {
        t[i] = t[i - 1] * 2;
    }
    for (int i = 0; i < 30; i++) {
        if (i % 2) q1 += t[i];
        else q2 += t[i];
    }
    cout << q1 << endl;
    cin >> a1;
    a1 -= 2 * q1;
    vector<int> t2(32, 1);
    vector<int> xy(33);
    for (int i = 0; i < 31; i += 2) {
        if (a1 <= 0) break;
        if (a1 & 1) {
            xy[i]++;
            a1 >>= 2;
        } else {
            a1 >>= 1;
            if (a1 & 1) {
                xy[i] += 2;
            }
            a1 >>= 1;
        }
    }
    cout << q2 << endl;
    cin >> a2;
    a2 -= 2 * q2;
    a2 >>= 1;
    for (int i = 1; i < 31; i += 2) {
        if (a2 <= 0) break;
        if (a2 & 1) {
            xy[i]++;
            a2 >>= 2;
        } else {
            a2 >>= 1;
            if (a2 & 1) {
                xy[i] += 2;
            }
            a2 >>= 1;
        }
    }
    cout << '!' << endl;
    int m;
    cin >> m;
    for (int i = 0; i < 31; i++) {
        if (m <= 0) break;
        if (m & 1) xy[i] = 2;
        m >>= 1;
    }
    long long ans = 0;
    for (int i = 0; i < 31; i++) {
        ans += (long long) xy[i] * t[i];
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}