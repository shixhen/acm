#include <bits/stdc++.h>

using namespace std;

int bfs(int k, long long x) {
    queue<array<long long, 3>> q;
    q.push({k, 0, 0});
    int res = 0;
    map<long long, int> mp;
    while (!q.empty()) {
        auto [cur, step, cnt] = q.front();
        q.pop();
        long long j = 31;
        while (j) {
            if ((cur & (1ll << j)) == 0) {
                j--;
                continue;
            }
            while (j && (cur & (1ll << j)) == 1) {
                j--;
            }
            if (j == 0 && (cur & 1) == 1) {
                
            }
        }
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    while ((n & 1) == 0) {
        n >>= 1;
    }
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 0; (1 << i) <= n; i++) {
        if (((n >> i) & 1) == 0) {
            cnt++;
        } else {
            cnt1++;
        }
    }
    if (k > cnt) {
        cout << cnt1 + k - 1 << "\n";
        return;
    }

    return;
}


int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}