#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int ans = 1;
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 1; j < a.size(); j++) {
            if (a[i] == b[j] && a[i + 1] == b[j - 1]) ans <<= 1;
        }
    }
    cout << ans;
    return 0;
}