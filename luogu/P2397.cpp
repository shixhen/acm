#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = -1;
    int cnt = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x != ans) {
            cnt--;
            if (cnt < 0) {
                ans = x;
                cnt = 1;
            }
        } else {
            cnt++;
        }
        
    }
    cout << ans << endl;
    return 0;
}