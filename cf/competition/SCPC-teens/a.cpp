#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int p = 1;
    deque<int> ans;
    for (int i = 1; i <= n; i++) {
        if (p % 2 == 0) {
            ans.push_back(i);
        } else {
            ans.push_front(i);
        }
        if (i % 4) {
            p = 1 - p;
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
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