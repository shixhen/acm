#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int cnts = 0;
    int cntb = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > k) cntb++;
        else cnts++;
        if (cnts >= cntb) {
            if (cnts == 1 and a[1] > k and i == 1) continue;
            cnt++;
            if (cnt >= 2) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cnts = 0;
    cntb = 0;
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > k) cntb++;
        else cnts++;
        if (cnts >= cntb) {
            if (cnts == 1 and a[n - 2] > k and i == n - 2) continue;
            cnt++;
            if (cnt >= 2) {
                cout << "Yes\n";
                return;
            }
            
        }
    }
    cnts = 0;
    cntb = 0;
    int l = 0;
    for (; l < n; l++) {
        if (a[l] > k) cntb++;
        else cnts++;
        if (cnts >= cntb) {
            break;
        }
    }
    cnts = 0;
    cntb = 0;
    int r = n - 1;
    for (; r >= 0; r--) {
        if (a[r] > k) cntb++;
        else cnts++;
        if (cnts >= cntb) {
            break;
        }
    }
    if (r > l + 1) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}