#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<long long> cnt(n + 1);
    long long sum = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
        sum++;
    }
    long long ans = 0; 
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 1) {
            ans += cnt[i] * (cnt[i] - 1) * (sum - cnt[i]) / 2ll;
        }
    }
    cout << ans << "\n";
    return 0;
}