#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int x;
    while (n--) {
        cin >> x;
        if (x == 0) {
            x++;
        }
        sum += x;
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}