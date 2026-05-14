#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            auto it = lower_bound(a.begin(), a.end(), x);
            if (it == a.end()) {
                a.push_back(x);
                cnt++;
            } else {
                a[it - a.begin()] = x;
            }
        }
        cout << cnt << "\n";
    }


    return 0;
}