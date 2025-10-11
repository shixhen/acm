#include <bits/stdc++.h>

using namespace std;

int a[7];
bool dp[1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 6; i++) {
        cin >> a[i];
    }
    dp[0] = true;
    while (a[1]--) {
        for (int i = 1000; i >= 1; i--) {
            dp[i] |= dp[i - 1];
        }
    }
    while (a[2]--) {
        for (int i = 1000; i >= 2; i--) {
            dp[i] |= dp[i - 2];
        }
    }
    while (a[3]--) {
        for (int i = 1000; i >= 3; i--) {
            dp[i] |= dp[i - 3];
        }
    }
    while (a[4]--) {
        for (int i = 1000; i >= 5; i--) {
            dp[i] |= dp[i - 5];
        }
    }
    while (a[5]--) {
        for (int i = 1000; i >= 10; i--) {
            dp[i] |= dp[i - 10];
        }
    }
    while (a[6]--) {
        for (int i = 1000; i >= 20; i--) {
            dp[i] |= dp[i - 20];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (dp[i]) {
            ans++;
        }
    }
    cout << "Total=" << ans;

    return 0;
}