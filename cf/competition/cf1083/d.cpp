#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        pre[i] = st.size() + 1;
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    vector<int> suf(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        suf[i] = st.size() + 1;
        st.push(i);
    }
    int mx = max(suf[1], pre[n]);
    for (int i = 2; i < n; i++) {
        mx = max(mx, pre[i] + suf[i] - 1);
    }
    cout << n - mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}