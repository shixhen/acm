#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        while (a[i] != b[i] && i < n) {
            i++;
        }
        ans++;
    }
    cout << ans;
    return 0;
}