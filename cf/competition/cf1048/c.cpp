#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;
    long long a = 1ll << k;
    long long b = a;
    long long c = x;
    long long d = a + b - c;
    vector<int> ans;
    while (c != d) {
        if (c < d) {
            d -= c;
            c <<= 1;
            ans.push_back(1);
        } else {
            c -= d;
            d <<= 1;
            ans.push_back(2);
        }
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";

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