#include <bits/stdc++.h>

using namespace std;



bool cmp(array<int, 3> a, array<int, 3> b) {
    if (a[1] == b[1]) {
        return a[2] > b[2];
    }
    return a[1] < b[1];
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    int idx = 1;
    for (auto &i : a) {
        cin >> i[1] >> i[2];
        i[0] = idx++;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> ans;
    int last = 0;
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][1] == last || a[i][2] <= maxn)
            continue;
        last = a[i][1];
        maxn = a[i][2];
        ans.push_back(a[i][0]);
    }
    cout << ans.size() << "\n";
    if (ans.size()) {
        sort(ans.begin(), ans.end());
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}