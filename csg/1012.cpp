#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int l, r;
    while (cin >> l >> r) {
        while (l != r) {
            if (l > r) swap(l, r);
            r >>= 1;
        }
        cout << l << '\n';
    }
    return 0;
}