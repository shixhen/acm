#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> cnt0(1005);
    vector<int> cnt1(1005);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            cnt0[x]++;
        } else {
            cnt1[x]++;
        }
    }
    int max1 = 0;
    int max0 = 0;
    for (int i = 0; i <= 1000; i++) {
        max0 = max(max0, cnt0[i]);
        max1 = max(max1, cnt1[i]);
    }
    cout << n - max0 - max1 << "\n";
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