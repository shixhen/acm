#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        int cnt = 0;
        while (cnt < m) {
            if (a[cnt] > n) break;
            n -= a[cnt];
            cnt++;
        }
        cout << cnt << "\n";
    }
    
    

    return 0;
}