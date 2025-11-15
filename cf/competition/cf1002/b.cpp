#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int i = 2;
    while(i <= n) {
        int flag = 0;
        int f2;
        for (int j = i; j <= n - k + i; j++) {
            if (a[j] != i / 2) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && n - k + 1 >= 2) {
            i += 2;
            break;
        }
        if (flag) break;
        i += 2;
    }
    cout << i / 2 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}