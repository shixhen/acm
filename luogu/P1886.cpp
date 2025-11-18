#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> q(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && a[q[r]] >= a[i]) {
            r--;
        }
        while (l <= r && q[l] + k <= i) {
            l++;
        }
        q[++r] = i;
        if (i >= k) {
            cout << a[q[l]] << ' ';
        }
    }
    cout << '\n';
    l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && a[q[r]] <= a[i]) {
            r--;
        }
        while (l <= r && q[l] + k <= i) {
            l++;
        }
        q[++r] = i;
        if (i >= k) {
            cout << a[q[l]] << ' ';
        }
        
    }

    return 0;
}