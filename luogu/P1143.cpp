#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<char> s = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                     'A', 'B', 'C', 'D', 'E', 'F'};
    int n;
    cin >> n;
    string a;
    cin >> a;
    int m;
    cin >> m;
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum *= n;
        sum += find(s.begin(), s.end(), a[i]) - s.begin();
    }
    vector<char> ans;
    while (sum) {
        ans.push_back(s[sum % m]);
        sum /= m;
    }
    if (ans.empty()) {
        ans.push_back('0');
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}