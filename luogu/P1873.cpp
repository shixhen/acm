#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    auto check = [&] (int k) {
        int cnt = 0;
        for (auto &i: a) {
            cnt += max(0, i - k);
            if (cnt >= m) return true;
        }
        return false;
    };
    int l = 1, r = 1e6;
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
    return 0;
}