#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<vector<int>> tr(100005, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = s[i] - 'a';
            
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}