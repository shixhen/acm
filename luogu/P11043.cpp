#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    string f;
    int x;
    vector<int> a(n);
    while (cin >> f) {
        if (f == "add") {
            cin >> x;
            a[0]++;
        } else if (f == "sync") {
            cin >> x;
            a[x]++;
        } else {
            int ans = a[0];
            for (int i = 1; i < n; i++) {
                ans = min(ans, a[i]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}