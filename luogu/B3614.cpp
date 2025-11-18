#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    stack<unsigned long long> st;
    unsigned long long t;
    while (n--) {
        cin >> a;
        if (a == "push") {
            cin >> t;
            st.push(t);
        } else if (a == "query") {
            if (st.size()) {
                cout << st.top() << '\n';
            } else {
                cout << "Anguei!" << '\n';
            }
        } else if (a == "size") {
            cout << st.size() << '\n';
        } else {
            if (st.size()) {
                st.pop();
            } else {
                cout << "Empty" << '\n';
            }
        }
    }

    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}