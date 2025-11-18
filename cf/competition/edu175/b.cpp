#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x, k;
    cin >> n >> x >> k;
    int step = 0;
    string s;
    cin >> s;
    long long ans = 0;
    int flag = 0;
    int round = 0;
    int f = 0;
    for (int i = 0; i < n && i < k; i++) {
        if (s[i] == 'L') step--;
        else step++;
        if (step == 0 && round == 0) {
            round = i + 1;
        }
        if (step + x == 0 && flag == 0) {
            flag = 1;
            f = i + 1;
        }
    }
    if (flag) {
        ans++;
        if (round != 0) ans += (long long) (k - f) / (long long) round;
        cout << ans << '\n'; 
    } else {
        cout << 0 << '\n';
        return;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}