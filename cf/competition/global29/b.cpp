#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "2 1 2 1\n";
        return;
    }
    vector<int> ans(n * 2 + 1);
    int p = 1;
    int num = n;
    while (num > 0) {
        ans[p + num] = num;
        ans[p++] = num;
        num -= 2;
    }
    ans[p] = n - 1;
    ans[p + n - 1] = n - 1;
    p = n + 2;
    num = n - 3;
    while (num > 1) {
        ans[p + num] = num;
        ans[p++] = num;
        num -= 2;
    }
    if (num == 1) {
        ans[++p] = 1;
    }
    if (ans[2 * n] == 0) {
        ans[2 * n] = 1;
    }
    
    
    for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) { solve(); }

    return 0;
}