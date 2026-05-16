#include <bits/stdc++.h>

using namespace std;

int a[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    for (int i = mx; i <= sum; i++) {
        if (sum % i != 0) continue;
    }
    return 0;
}