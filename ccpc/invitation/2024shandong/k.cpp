#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int tot = 1;
    cout << "Yes\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << tot++ << " ";
            if (tot > 2 * n) tot = 1;
        }
        cout << "\n";
    }

    return 0;
}