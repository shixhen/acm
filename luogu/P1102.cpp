#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, c;
    cin >> n >> c;
    map<int, int> mp;
    vector<int> a(n);
    long long ans = 0;
    for (auto &i: a) cin >> i, mp[i]++;
    for (auto &i: a) ans += mp[i - c];
    cout << ans;
    return 0;
}