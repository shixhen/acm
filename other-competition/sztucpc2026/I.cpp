#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cout << (((n & 1) && cnt1 > cnt0) ? "Frieren" : "Aura") << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}