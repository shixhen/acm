#include <bits/stdc++.h>

using namespace std;

int a[305][305];
int num[305] = {0};

void solve() {
    memset(a, 0, sizeof(a));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        num[i] = 0;
        for (int j = n; j >= 2; j--) {
            if (a[i][j] == 1) num[i]++;
            else break;
        }
    }
    sort(num + 1, num + 1 + n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (num[i] >= ans) ans++;
    }
    cout << ans << "\n";
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