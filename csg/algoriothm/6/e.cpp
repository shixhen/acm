#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> a(2 * n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < (int) a.size(); i += 2) {
            ans += min(a[i], a[i + 1]);
        }
        cout << ans << "\n";
    }


    return 0;
}