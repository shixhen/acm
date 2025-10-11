#include <bits/stdc++.h>

using namespace std;

int move(int x) {
    cout << x << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (auto &i: a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        x = 0;
        for (; x < n; x++) {
            if (a[x] != x) {
                break;
            }
        }
        while (x != -1) {
            x = move(x);
        }
    }
    return 0;
}