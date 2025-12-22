#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt1(32);
    vector<int> cnt0(32);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int j = 0;
        if (i % 2) {
            while (a[i]) {
                if (a[i] & 1) cnt0[j]++;
                a[i] >>= 1;
                j++;
            }
        } else {
            while (a[i]) {
                if (a[i] & 1) cnt1[j]++;
                a[i] >>= 1;
                j++;
            }
        }
        
    }
    // for (int i = 0; i < 32; i++) {
    //     cout << cnt0[i] << " ";
    //     cout << cnt1[i] << "\n";
    // }
    int odd, even;
    even = n / 2;
    odd = n - even;
    int res = 0;
    for (int i = 0; i < 32; i++) {
        res += min(cnt0[i], even - cnt0[i]);
        res += min(cnt1[i], odd - cnt1[i]);
    }
    cout << res << "\n";
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