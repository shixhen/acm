#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio;
    cin.tie(NULL), cout.tie(NULL);
    int w;
    int n;
    cin >> w >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int ans = n;
    while (l < r) {
        if (a[l] + a[r] <= w) {
            ans--;
            l++;
        }
        r--;
    }
    cout << ans;
    return 0;
}