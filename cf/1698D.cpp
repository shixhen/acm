#include <bits/stdc++.h>

using namespace std;

void ask(int x, int y, set<int> &b) {
    cout << "? " << x << " " << y << endl;
    int val;
    for (int i = 1; i <= (y - x + 1); i++) {
        cin >> val;
        b.insert(val);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> vis(n + 1, false);
        const auto check = [&](int x) {
            set<int> b;
            ask(1, x, b);
            int cnt = 0;
            for (int i = 1; i <= x; i++) {
                if (b.count(i)) {
                    cnt++;
                }
            }
            return cnt % 2;
        };
        int l = 1, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}