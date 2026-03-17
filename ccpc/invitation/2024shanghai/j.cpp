#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 10;
bool prime[N];
void init() {
    fill(prime, prime + N, true);
    for (int i = 2; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0x3f3f3f3f;
    for (int l = 1; l <= n; l++) {
        int sum = 0;
        for (int r = l; r <= n; r++) {
            sum += a[r];
            if (!prime[sum]) {
                ans = min(ans, r - l);
            }
        }
    }
    if (ans == 0x3f3f3f3f) {
        ans = -1;
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}