#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (1) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        if (!next_permutation(a.begin(), a.end())) break;
    }
    return 0;
}