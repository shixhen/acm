#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    
    for (auto &i: a) {
        cin >> i;
        sum += i;
        if (i == 0) {
            cnt0++;
        } else if (i == 1) {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    if (sum > s) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        return;
    }
    if (sum == s || (s - sum) % 3 == 0 || (s - sum) % 2 == 0) {
        cout << "-1\n";
        return;
    }
    if (s - sum > 3 and (s - sum - 3) % 2 == 0) {
        cout << "-1\n";
        return;
    }
    while (cnt0--) {
        cout << "0 ";
    }
    while (cnt2--) {
        cout << "2 ";
    }
    for (int i = 1; i <= cnt1; i++) {
        cout << "1" << " \n"[i == cnt1];
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}