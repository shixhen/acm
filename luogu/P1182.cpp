#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    auto check = [&](int x) {
        int cnt = 1;
        long temp = 0;
        for (auto i: a) {
            if (i > x) return false;
            if (temp + i > x || temp > (int) 1e9) {
                cnt++;
                temp = 0;
            }
            temp += i;
            if (cnt > m) return false;
        }
        return true;
    };
    int l = 0, r = 1e9;
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}