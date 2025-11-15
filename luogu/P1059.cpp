#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m, s, t;
    cin >> m >> s >> t;
    int run = 0, walk = 0;
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            m -= 10;
            run += 60;
            walk += 17;
        } else {
            walk = max(walk, run);
            m += 4;
            walk += 17;
        }
        if (max(run, walk) >= s) {
            cout << "Yes\n";
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No\n" << max(run, walk) << '\n';

}