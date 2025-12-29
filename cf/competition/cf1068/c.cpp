#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    set<int> s;
    set<int> s2;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        if (!s2.count(a[i])) {
            b.push_back(a[i]);
            for (int j = a[i]; j <= k; j += a[i]) {
                if (!s.count(j)) {
                    cout << "-1\n";
                    return;
                }
                s2.insert(j);
            }
        }
    }
    cout << b.size() << "\n";
    for (int &x : b) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}