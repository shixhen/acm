#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (auto &i : a) {
        cin >> i;
        sum += i;
    }
    for (int i = 0; i < n; i++) {
        if (sum - a[i] == m) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}