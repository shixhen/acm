#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto check = [&] (int x) {
        unordered_set<int> s;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < x) {
                s.insert(a[i]);
                if (s.size() == x) {
                    cnt++;
                    s.clear();
                    if (cnt == k) return true;
                }
            }
        }
        return false;
    };
    int l = 0, r = 200005;
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}