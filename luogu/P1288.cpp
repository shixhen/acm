#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int p1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            p1 = i;
            break;
        }
    }
    int p2;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            p2 = i;
            break;
        }
    }
    if (p1 % 2 || (n - p2 + 1) % 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}