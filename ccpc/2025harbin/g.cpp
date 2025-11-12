#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> h(n + 1, vector<long long>(m + 1));
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<long long> st;
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            if (h[i - 1][j] > 0) {
                h[i][j] += h[i - 1][j];
                h[i - 1][j] = 0;
            }
            while (!st.empty() && h[i][j] < 0) {
                long long t = min(h[i][st.top()], -h[i][j]);
                h[i][st.top()] -= t;
                h[i][j] += t;
                if (h[i][st.top()] == 0) {
                    st.pop();
                }
            }
            if (h[i][j] > 0) {
                st.push(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += abs(h[i][j]);
        }
    }
    cout << ans << "\n";
    return;
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