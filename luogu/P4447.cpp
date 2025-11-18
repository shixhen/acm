#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0x3f3f3f3f;
    int temp = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 != a[i - 1]) {
            ans = min(temp, ans);
            temp = 1; 
        } else temp++;
    }
    ans = min(temp, ans);
    cout << ans;
    return 0;
}