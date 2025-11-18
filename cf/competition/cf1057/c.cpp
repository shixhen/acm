#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long , int> mp;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    sort(a.begin(), a.end(), greater<long long>());
    long long ans = 0;
    // 对称边长度之和
    long long sum = 0;
    // 边的数量
    int num = 0;
    for (auto &[x, cnt] : mp) {
        //cout << x << " " << cnt << "\n";
        sum += x * (cnt / 2);
        num += cnt / 2;
    }
    sum *= 2;
    num *= 2;
    if (sum == 0) {
        cout << "0\n";
        return;
    }
    //cout << sum << "\n";
    vector<long long> b;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] % 2 == 1) {
            b.push_back(a[i]);
        }
    }
    b.push_back(0);
    long long k = 0;
    sort(b.begin(), b.end());
    for (int i = 0; i < (int)b.size() - 1; i++) {
        auto it = lower_bound(b.begin(), b.end(), sum + b[i]);
        if (it == b.end()) it--;
        while (it != b.begin() && *it >= sum + b[i]) it--;
        if (*it <= b[i]) continue;
        k = max(k, b[i] + *it);
    }
    if (k != 0) num++;
    if (num < 3) {
        cout << "0\n";
        return;
    }
    ans = sum + k;
    cout << ans << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}