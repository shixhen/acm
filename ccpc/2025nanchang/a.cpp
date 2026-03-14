#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    vector<int> v0, v1, v2, v3;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 4 == 0) {
            cnt0++;
            v0.push_back(i);
        } else if (a[i] % 4 == 1) {
            cnt1++;
            v1.push_back(i);
        } else if (a[i] % 4 == 2) {
            cnt2++;
            v2.push_back(i);
        } else if (a[i] % 4 == 3) {
            cnt3++;
            v3.push_back(i);
        }
    }
    if (cnt2 * 2 + cnt3 < cnt1) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for (auto x : v0) {
        ans.push_back(x);
    }
    while (v2.size() > 0 && v1.size() >= 2) {
        ans.push_back(v2.back());
        ans.push_back(v1[v1.size() - 1]);
        ans.push_back(v1[v1.size() - 2]);
        v2.pop_back();
        v1.pop_back();
        v1.pop_back();
    }
    while (v3.size() > 0 && v1.size() > 0) {
        ans.push_back(v3.back());
        ans.push_back(v1.back());
        v3.pop_back();
        v1.pop_back();
    }
    while (v3.size() >= 2 && v2.size() > 0) {
        ans.push_back(v3.back());
        ans.push_back(v3[v3.size() - 2]);
        ans.push_back(v2.back());
        v3.pop_back();
        v3.pop_back();
        v2.pop_back();
    }
    while (v2.size() >= 2) {
        ans.push_back(v2.back());
        ans.push_back(v2[v2.size() - 2]);
        v2.pop_back();
        v2.pop_back();
    }
    if (v3.size() > 0 || v1.size() > 0) {
        cout << "-1\n";
        return;
    }
    for (auto x : v2) {
        ans.push_back(x);
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}