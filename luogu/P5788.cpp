#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    for (auto &i: a) cin >> i;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (st.size() && a[st.top()] < a[i]) {
            ans[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}