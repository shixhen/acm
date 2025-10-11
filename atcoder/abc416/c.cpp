#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    for (auto &i: s)
        cin >> i;
    vector<string> a;
    function<void(int, string)> dfs = [&](int d, string ss) {
        if (d > k) {
            a.push_back(ss);
            return;
        }
        for (int i = 0; i < n; i++) {
            dfs(d + 1, ss + s[i]);
        }
        return;
    };
    dfs(1, "");
    sort(a.begin(), a.end());
    cout << a[x - 1];

    return 0;
}