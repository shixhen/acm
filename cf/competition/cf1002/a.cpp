#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    set<int> a;
    set<int> b;
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a.insert(temp);
    }
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        b.insert(temp);
    }
    if ((a.size() == 1 && b.size() <= 2)|| (b.size() == 1 && a.size() <= 2)) {
        cout << "NO" << "\n";
    } else cout << "YES" << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}