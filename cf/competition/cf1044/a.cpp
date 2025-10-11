#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(105);
    int x;
    bool f = false;
    while (n--) {
        cin >> x;
        cnt[x]++;
        if (cnt[x] >= 2) {
            f = true;
            
        }
    }
    if (f) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}