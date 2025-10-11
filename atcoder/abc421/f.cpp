#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    vector<int> a(q + 2);
    a[0] = -1;
    long long sum = 0, sum2 = 0;
    int op, x, y, t, t2;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            a[i] = a[x];
            a[x] = i;
        } else {
            cin >> x >> y;
            t = a[x];
            t2 = a[y];
            sum2 = 0;
            sum = 0;
            while (1) {
                if (t == y) {
                    cout << sum << "\n";
                    a[x] = y;
                    break;
                }
                if (t2 == x) {
                    cout << sum2 << "\n";
                    a[y] = x;
                    break;
                }
                if (t != -1) {
                    sum += t;
                    t = a[t];
                }
                if (t2 != -1) {
                    sum2 += t2;
                    t2 = a[t2];
                }
            }
        }
    }
    return 0;
}