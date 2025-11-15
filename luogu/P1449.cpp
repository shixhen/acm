#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string a;
    cin >> a;
    stack<long long> st;
    long long temp = 0;
    long long x, y;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '@') break;
        if (a[i] == '.') continue;
        else if (isdigit(a[i])) {
            while (isdigit(a[i])) {
                temp = temp * 10 + (a[i] - '0');
                i++;
            }
            st.push(temp);
            temp = 0;
        } else {
            if (a[i] == '+') {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(x + y);
            } else if (a[i] == '*') {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(x * y);
            } else if (a[i] == '/') {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y / x);
            } else {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y - x);
            }
        }
    }
    cout << st.top();
    return 0;
}