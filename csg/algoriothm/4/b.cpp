#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int ans = 0;
        int t = 0;
        int x;
        while (n--) {
            cin >> x;
            t += x;
            ans = max(ans, t);
            t = max(t, 0);
        }
        cout << ans << endl;
    }

    return 0;
}