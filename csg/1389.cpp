#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> s1, s2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                while (s2.size() and s2.top() == 1) {
                    cout << s[s1.top()];
                    s1.pop();
                    s2.pop();
                }
                if (s2.size()) {
                    int temp = s2.top() + 1;
                    s2.pop();
                    s2.push(temp);
                }
            } else {
                s1.push(i);
                s2.push(0);
            }
        }
        cout << "\n";
    }
    return 0;
}