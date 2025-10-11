#include <bits/stdc++.h>

using namespace std;

int ask(vector<int> &a) {
    cout << "? ";
    cout << a.size();
    for (auto &i: a) {
        cout << " " << i;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (auto &i: a) {
            cin >> i;
        }
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
        }
        int l = 1, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            vector<int> v(mid);
            iota(v.begin(), v.end(), 1);
            if (ask(v) > a[mid - 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}