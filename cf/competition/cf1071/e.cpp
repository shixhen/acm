#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int cnt = 0;
    for (auto &ch : s) {
        if (ch == '0') cnt++;
        else cnt--;
    }
    vector<long long> p(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    if (x - cnt < y || x + y < sum) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}