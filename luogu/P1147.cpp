#include <bits/stdc++.h>

using namespace std;

int c(int l, int r) {
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int l = 1, r = 2, res;
    while (r < n) {
        res = c(l, r);
        if (res == n) {
            cout << l << ' ' << r << '\n';
            l++;
        } else if (res < n) {
            r++;
        } else {
            l++;
        }

    }
    return 0;
}