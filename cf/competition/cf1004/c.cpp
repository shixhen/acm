#include <bits/stdc++.h>

using namespace std;

int d(long long x) {
    int len = 0;
    while(x > 0) {
        x /= 10;
        len++;
    }
    return len;
}

bool check (long long x) {
    while (x > 0) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

void solve() {
    long long n;
    cin >> n;
    long long nine = 9;
    int t = 1;
    int ans = 100;
    while(t <= d(n) + 1) {
        long long temp = n;
        int cnt = 0;
        while(!check(temp) && cnt <= 9) {
            temp += nine;
            cnt++;
        }
        ans = min(ans, cnt);
        nine = nine * 10 + 9;
        t++;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}