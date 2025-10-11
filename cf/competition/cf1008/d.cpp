#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    char ch;
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> ch;
        cin >> t;
        if (ch == '+') a[i][0] = -t;
        else a[i][0] = t;
        cin >> ch;
        cin >> t;
        if (ch == '+') a[i][1] = -t;
        else a[i][1] = t;  
    }
    long long l = 1, r = 1;
    long long add = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][1] < 0 && a[i][0] < 0) {
            add -= a[i][0];
            add -= a[i][1];
        } else if (a[i][0] < 0 && a[i][1] > 0) {
            r += add;
            add = (a[i][1] - 1) * r;
            add -= a[i][0];
        } else if (a[i][0] > 0 && a[i][1] < 0) {
            l += add;
            add = (a[i][0] - 1) * l;
            add -= a[i][1];
        } else {
            if (a[i][0] > a[i][1]) {
                l += add;
                add = (a[i][0] - 1) * l;
                add += (a[i][1] - 1) * r;
            } else if (a[i][0] < a[i][1]) {
                r += add;
                add = (a[i][1] - 1) * r;
                add += (a[i][0] - 1) * l;
            } else {
                add += (add + r + l) * (a[i][0] - 1);
            }
        }
    }
    cout << add + r + l << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}