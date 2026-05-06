#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> cnta(n + 1);
    vector<int> cntb(n + 1);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //cnta[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        // if (b[i] != -1) {
        //     cntb[b[i]]++;
        // }
    }
    vector<int> temp(n + 1);
    int t = 0;
    for (int i = 1; i <= k; i++) {
        cnta[a[i]]++;
        if (b[i] == -1) {
            t++;
        } else {
            cntb[b[i]]++;
        }
        if (cntb[b[i]] > cnta[a[i]]) {
            cout << "No\n";
            return;
        }
        temp[a[i]]++;
        if (b[i] != -1) {
            temp[b[i]]--;
        }
        
    }
    cout << "Yes\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}