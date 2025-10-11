#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    int l = 0, r = n - 1;
    int x, y, z;
    while (l < r - 1) {
        x = a[l];
        y = a[r - 1];
        z = a[r];
        if (x > y and x > z) {
            cout << "RLR";
        } else if (z > x and z > y) {
            cout << "LRR";            
        } else if (x < max(y, z) and x > min(y, z)) {
            cout << "LRR";
        } else {
            cout << "RLR";
        }
        l++;
        r -= 2;
    }
    for (int i = l; i <= r; i++) {
        cout << "L";
    }
    cout << "\n";
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