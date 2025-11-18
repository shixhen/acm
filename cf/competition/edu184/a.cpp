#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > a) {
            cntb++;
        } else if (v[i] < a) {
            cnta++;
        }
    }
    if (cnta >= cntb) {
        cout << a - 1 << "\n";
    } else {
        cout << a + 1 << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
