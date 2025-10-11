#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    char ch;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ch;
        a[i] = ch == 'y';
        if (a[i]) ans++;
        a[i] += a[i - 1];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] && a[i] == a[i + 1]) {
            ans++;
            i++;
        }
    }
    cout << ans;
}