#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k;
    map<int, int> cnta;
    map<int, int> cntb;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i: a) {
        cin >> i;
        x = i % k;
        x = min(x, k - x);
        cnta[x]++;
    }
    for (auto &i: b) {
        cin >> i;
        x = i % k;
        x = min(x, k - x);
        cntb[x]++;
    }
    for (auto &[num, cnt] : cntb) {
        if(cntb[num] > cnta[num]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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