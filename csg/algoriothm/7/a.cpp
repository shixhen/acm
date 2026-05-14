#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        do {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        } while (next_permutation(a.begin(), a.end()));
    }

    return 0;
}