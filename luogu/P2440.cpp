#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int l = 0, r = 1e9;
    int mid;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    auto check = [&] (int x) {
        int cnt = 0;
        for (auto &i: a) {
            cnt += i / x;
        }
        return cnt >= k;
    };
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
    return 0;
}