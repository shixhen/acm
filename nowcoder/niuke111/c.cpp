#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &i: a) cin >> i;
    vector<int> num(n);
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            int cnt = 1;
            int j = i;
            while (a[j] == a[j + 1] && j < n - 1) {
                j++;
                cnt++;
            }
            ans = max(ans, cnt);
            for (int k = i; k <= j; k++) {
                num[k] = cnt;
            }
            i = j;
        } else {
            num[i] = 1;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] != a[i + 1] && a[i] != a[i - 1] && a[i - 1] == a[i + 1]) {
            ans = max(ans, num[i - 1] + num[i + 1]);
        }
    }
    cout << ans;
}