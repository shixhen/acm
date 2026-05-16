#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a = {100, 50, 20, 10, 5, 2, 1};
        int cnt = 0;
        int sum = n;
        vector<pair<int, int>> ans;
        for (int i = 0; i < 7; i++) {
            if (a[i] > n) continue;
            ans.push_back({a[i], n / a[i]});
            cnt += n / a[i];
            n %= a[i];
        }
        cout << cnt << " ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first;
            if (ans[i].second > 1) {
                cout << "*" << ans[i].second;
            }
            if (i != ans.size() - 1) cout << "+";
            else cout << "=" << sum << "\n";
        }
    }

    return 0;
}