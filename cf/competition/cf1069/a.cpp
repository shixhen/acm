#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (!s.count(s.size())) {
        s.insert(s.size());
    }
    cout << s.size() << "\n";
    return;
}

int main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}