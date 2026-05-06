#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 0;
    int n;
    cin >> n;
    for (int x = 1; x <= n; x++) {
        ans = max(ans, n - max(x, (n - 1) / x + 1));
    }
    cout << ans << "\n";
    int m = n - ans;
    vector<vector<int>> a;
    //cout << m << "----\n";
    int t = n % m;
    int b = 1;
    for (int i = 1; i <= t; i++) {
        vector<int> temp;
        for (int j = 1; j <= n / m + 1; j++) {
            temp.push_back(b);
            b++;
        }
        //cout << 1111 << endl;
        a.push_back(temp);
    }
    t = m - t;
    //cout << t << " " << m << endl;
    for (int i = 1; i <= t; i++) {
        vector<int> temp;
        for (int j = 1; j <= n / m; j++) {
            temp.push_back(b);
            b++;
            //cout << b << endl;
        }
        
        a.push_back(temp);
    }
    vector<pair<int, int>> ans2;
    for (auto &x : a) {
        for (int i = 0; i < (int) x.size() - 1; i++) {
            ans2.emplace_back(x[i], x[i + 1]);
        }
    }
    vector<pair<int, int>> ans3;
    for (int j = 0; j < (int) a[0].size(); j++) {
        for (int i = 0; i < (int) a.size() - 1; i++) {
            if (a[i].size() <= j || a[i + 1].size() <= j) {
                continue;
            }
            ans3.emplace_back(a[i][j], a[i + 1][j]);
        }
    }
    for (int i = 0; i < ans; i++) {
        cout << ans2[i].first << " " << ans2[i].second << "\n";
    }
    for (int i = 0; i < ans; i++) {
        cout << ans3[i].first << " " << ans3[i].second << "\n";
    }
    return 0;
}