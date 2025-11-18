#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
    int n, amin = 1e8, amax = 0, mini, maxi;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < amin) {
            amin = a[i];
            mini = i;
        }
        if (a[i] > amax) {
            amax = a[i];
            maxi = i;
        }
    }
    int ans1, ans2;
    if (amax - amin > (n >> 1)) {
        cout << "?" << " " << maxi << " " << mini << endl;
        cout.flush();
        cin >> ans1;
        cout << "?" << " " << mini << " " << maxi << endl;
        cout.flush();
        cin >> ans2;
        if (ans1 == ans2 && ans1 >= amax - amin) cout << "! B\n";
        else cout << "! A\n";
        cout.flush();
    } else {
        if (n - amax > 0) {
            cout << "?" << " " << n << " " << 1 << endl;
            cout.flush();
            cin >> ans1;
            cout << "?" << " " << 1 << " " << n << endl;
            cout.flush();
            cin >> ans2;
        } else {
            cout << "?" << " " << 1 << " " << n << endl;
            cout.flush();
            cin >> ans1;
            cout << "?" << " " << n << " " << 1 << endl;
            cout.flush();
            cin >> ans2;
        }
        if (ans1 == 0) cout << "! A\n";
        else cout << "! B\n";
        cout.flush();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}