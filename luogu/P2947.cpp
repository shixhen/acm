#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ans(n + 1);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (st.size() and a[i] > a[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}