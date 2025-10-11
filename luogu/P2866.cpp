#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.top()] <= a[i]) {
            ans += i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        ans += n - st.top();
        st.pop();
    }
    cout << ans;
    return 0;
}