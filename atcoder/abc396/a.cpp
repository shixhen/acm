#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] == a[i + 1] && a[i + 1] ==a[i + 2]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No" ;
    return 0;
}