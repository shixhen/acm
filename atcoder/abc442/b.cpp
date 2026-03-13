#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    int f = 0;
    int val = 0;
    int o;
    while (q--) {
        cin >> o;
        if (o == 1) {
            val++;
        } else if (o == 2) {
            val--;
            val = max(val, 0);
        } else {
            f = 1 - f;
        }
        if (f == 1 && val >= 3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}