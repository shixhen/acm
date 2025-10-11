#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string a;
    cin >> a;
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(') st.push(1);
        else {
            if (st.size()) st.pop();
            else {
                st.push(1);
                cnt++;
            }
        }
    }
    cout << cnt + (st.size() >> 1);
    return 0;
}