#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> cnt(n);
    for (auto &i: s) {
        cin >> i;
    }
    for (int i = 0; i < m; i++) {
        int cnt1 = 0, cnt0 = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        int f = 1;
        if (cnt1 > cnt0) {
            f = 0;
        } 
        for (int j = 0; j < n; j++) {
            if (s[j][i] == (f + '0')) {
                cnt[j]++;
            }
        }
    }
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        maxn = max(maxn, cnt[i]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (maxn == cnt[i]) ans.push_back(i);
    }
    
    sort(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}