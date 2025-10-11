#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    long double ans = 0;
    long double x = 0;
    long double temp = 0;
    vector<int> idx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 't') {
            idx.push_back(i);
        }
    }
    if (idx.size() < 2) {
        cout << "0.00000000000000000";
        return 0;
    }
    for (int i = 0; i < idx.size(); i++) {
        for (int j = i + 1; j < idx.size(); j++) {
            if (idx[j] - idx[i] < 2) continue;
            x = 0.0;
            for (int k = idx[i]; k <= idx[j]; k++) {
                if (s[k] == 't') {
                    x++;
                }
            }
            temp = (x - 2) / (double) ((idx[j] - idx[i] + 1) - 2);
            ans = max(ans, temp);
        }
    }
    
    cout << fixed << setprecision(10) << ans;
    return 0;
}