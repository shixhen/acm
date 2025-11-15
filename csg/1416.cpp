#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> c(n + 5, INT_MAX);
        for (int i = 0; i < a.size(); i++) {
            c[lower_bound(c.begin(), c.end(), a[i]) - c.begin()] = a[i];
        }
        for (int i = 0; i < c.size(); i++) {
            if (c[i] == INT_MAX) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}