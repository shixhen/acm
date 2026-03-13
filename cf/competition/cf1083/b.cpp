#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    int num = n;
    while ((num & 1) == 0) {
        ans <<= 1;
        for (int i = 1; i <= n; i++) {
            if ((num & 1) == 0) {
                num >>= 1;
            } else {
                break;
            }
        }
    }
    while ((num % 3) == 0) {
        ans *= 3;
        for (int i = 1; i <= n; i++) {
            if ((num % 3) == 0) {
                num /= 3;
            } else {
                break;
            }
        }
    }
    //cout << ans << " " << num << "\n";
    for (int i = 5; i * i <= num; i += 6) {
        int cnt = 0;
        while (num % i == 0) {
            num /= i;
            cnt++;
        }
        if (cnt) {
            cnt = (cnt - 1) / n + 1;
            for (int j = 0; j < cnt; j++) {
                ans *= i;
                //cout << i << "\n";
            }
        }
        
        cnt = 0;
        while (num % (i + 2) == 0) {
            cnt++;
            num /= (i + 2);
        }
        if (cnt) {
            cnt = (cnt - 1) / n + 1;
            for (int j = 0; j < cnt; j++) {
                ans *= (i + 2);
                //cout << i + 2 << "\n";
            }
        }
    }
    if (num > 1) {
        ans *= num;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}