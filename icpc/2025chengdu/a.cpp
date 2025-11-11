#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    int sum = 0;
    for (auto &i : a) {
        cin >> i;
        if (i == 0) cnt++;
        sum += i;
    }
    if (sum * 2 + n > 200 && sum * 2 - (n - cnt) <= 200) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }
    if (sum == 100) {
        for (auto &i : a) cout << i << " ";
        cout << "\n";
        return;
    }
    int need = abs(100 - sum) * 1000000;
    if (sum < 100) {

        for (auto &i : a) {
            i *= 1000000;
            if (need > 0) {
                i += min(need, 499999);
                need -= min(need, 499999);
            }
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (auto &i : a) {
        i *= 1000000;
        if (i > 0 && need > 0) {
            i -= min(need, 500000);
            need -= min(need, 500000);
        }
        cout << i << " ";
    }
    cout << "\n";
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
