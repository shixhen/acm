#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> c(1000005, 0);
    for (int i = 1; i < n; i++) {
        c[a[i]] = 1;
        for (int j = a[i] + 1; j < a[i + 1]; j++) {
            c[j] = c[j - a[i]] + 1;
        }
    }
    c[a[n]] = 1;
    vector<int> cnt(1000005, 0);
    for (int i = 1; i <= N; i++) {
        cnt[c[i]]++;
    }
    for (int i = 2; i <= N; i++) {
        cnt[i] += cnt[i - 1];
    }
    while (q--) {
        int x;
        cin >> x;
        cout << cnt[min(x, 1000000)] << " ";
    }
    return 0;
}