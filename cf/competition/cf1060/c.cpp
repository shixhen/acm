#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5;

bool prime[N];
vector<int> p;
void init() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = true;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!prime[i]) {
            p.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> b(n + 1);
    vector<long long> c(n + 1);
    map<int, bool> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mini;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i];
    }
    sort(c.begin() + 1, c.end());
    long long ans = c[1] + c[2];
    for (int i = 1; i <= n; i++) {
        if (b[i] == c[1]) {
            mini = i;
        }
        int t = a[i];
        for (auto &j : p) {
            if (j * j > t) break;
            if (t % j == 0) {
                if (mp.count(j)) {
                    cout << "0\n";
                    return;
                }
                mp[j] = true;
                while (t % j == 0) {
                    t /= j;
                }
            }
        }
        if (!prime[t]) {
            if (mp.count(t)) {
                cout << "0\n";
                return;
            }
            mp[t] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] < ans) {
            int t = a[i] + 1;
            for (auto &j : p) {
                if (j * j > t) break;
                if (t % j == 0 && mp.count(j)) {
                    ans = b[i];
                    break;
                }
                if (t % j == 0) {
                    while (t % j == 0) {
                        t /= j;
                    }
                }
            }
            if (!prime[t] && mp.count(t)) {
                ans = b[i];
                continue;
            }
        }
    }
    if (ans > c[1] * 2) {
        int t = a[mini];
        for (auto &j : p) {
            if (j * j > t) break;
            if (t % j == 0) {
                mp[j] = false;
                while (t % j == 0) {
                    t /= j;
                }
            }
        }
        if (!prime[t]) {
            mp[t] = false;
        }
        t = a[mini] + 2;
        for (auto &j : p) {
            if (j * j > t) break;
            if (t % j == 0 && mp[j]) {
                ans = c[1] * 2;
                break;
            }
            if (t % j == 0) {
                while (t % j == 0) {
                    t /= j;
                }
            }
        }
        if (!prime[t] && mp[t]) {
            ans = c[1] * 2;
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
