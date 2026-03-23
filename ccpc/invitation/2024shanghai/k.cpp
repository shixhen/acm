#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> a[50];
long long n, m;
long long ans = 0;
long long ans_b = 0;
long long ans_pre = 0;
void dfs(long long u, long long sum, long long pre, long long sum_b, long long d) {
    if (sum_b <= m) {
        if (sum > ans) {
            //cout << u << endl;
            ans = sum;
            ans_b = sum_b;
            ans_pre = pre;
        }
    }
    if (d == n) {
        return;
    }
    if (sum_b > m) {
        return;
    }
    
    dfs(u | (1 << d), sum + pre, pre + a[d].second, sum_b + a[d].first, d + 1);
    dfs(u, sum, pre, sum_b, d + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a, a + n, [&](auto &x, auto &y) {
        return x.second > y.second;
    });

    dfs(0ll, 0ll, 0ll, 0ll, 0ll);
    cout << ans << "\n";
    return 0;
}