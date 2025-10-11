#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int ans = 0;
    int x;
    cin >> n;
    while (n--) {
        cin >> x;
        ans ^= x;
    }
    cout << ans;
    return 0;
}