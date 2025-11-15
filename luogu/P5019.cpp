#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) sum += a[i] - a[i - 1];
    }
    sum += a[0];
    cout << sum;
    return 0;
}