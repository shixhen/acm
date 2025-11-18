#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p1 = 0, p2 = n - 1;
    int num = 1;
    while (p1 < p2) {
        if (p1 < p2 && a[p1] != num && a[p2] != num) {
            cout << "NO\n";
            return;
        }
        while (a[p1] == num && p1 < p2) {
            p1++;
            num++;
        }
        while (a[p2] == num && p1 < p2) {
            p2--;
            num++;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}