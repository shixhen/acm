#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 0;
    for (auto &c : s) {
        if (c == '1') {
            cnt = k;
        } else {     
            if (cnt <= 0) {
                ans++;
            }
            cnt--;
        }
    }
    cout << ans << "\n";
    return;
}


int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();
    }


    return 0;
}