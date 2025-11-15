#include <bits/stdc++.h>

using namespace std;

long long dp[300005];
void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> c(n + 1);
    vector<int> a(n + 1);
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[i] = a[i];
    }
    t[0] = 0;
    sort(t.begin(), t.end());
    int l = 0, r = n;
    int mid;
    while(l < r) {
        mid = (l + r) >> 1;
        int ok = true;
        int flag = 0;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == 'R' && a[i] > t[mid] && flag) {
                flag = 0;
            }
            if (c[i] == 'B' && a[i] > t[mid]) {
                if (flag == 0) {
                    flag = 1;
                    num++;
                }
                if (num > k) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) r = mid;
        else l = mid + 1;
    }
    cout << t[l] << '\n';
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}