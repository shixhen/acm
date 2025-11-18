#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    int len, c;
    cin >> c >> len;
    vector<pair<int, int>> a(n);
    for (auto &i: a) {
        cin >> i.second;
        cin >> i.first;
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].second > len + c) continue;
        if (s - a[i].first < 0) break;
        s -= a[i].first;
        ans++;
    }
    cout << ans;
    return 0;
}