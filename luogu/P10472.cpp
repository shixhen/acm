#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(-1);
    int max_len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(i);
        } else {
            if (!st.empty() && st.top() != -1) {
                char top_char = s[st.top()];
                if ((s[i] == ')' && top_char == '(') ||
                    (s[i] == ']' && top_char == '[') ||
                    (s[i] == '}' && top_char == '{')) {
                    st.pop();
                    max_len = max(max_len, i - st.top());
                } else {
                    st.push(i);
                }
            } else {
                st.push(i);
            }
        }
    }
    cout << max_len << endl;
    return 0;
}