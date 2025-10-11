#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int l, n, k;
    cin >> l >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - a[i - 1] > x) {
                cnt += (a[i] - a[i - 1])/ x;
                if ((a[i] - a[i - 1]) % x == 0) cnt--;
                if (cnt > k) return false;
            }
        }
        return true;
    };
    int ll = 1, r = 1e9;
    int mid;
    while (ll < r) {
        mid = (ll + r) >> 1;
        if (check(mid)) r = mid;
        else ll = mid + 1;
    }
    cout << ll << '\n';
    return 0;
}