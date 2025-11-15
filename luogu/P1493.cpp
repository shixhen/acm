#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> cnt(n + 2, INT_MAX);
    int t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        b[t] = i;
    }
    for (int i = 0; i < n; i++) {
        cnt[lower_bound(cnt.begin(), cnt.end(), b[a[i]]) - cnt.begin()] = b[a[i]]; 
    }
    for (int i = 0; i < n + 1; i++) {
        if (cnt[i] == INT_MAX) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}