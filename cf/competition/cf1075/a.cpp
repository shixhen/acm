#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    int cnt = 0;
    int cnt2 = 0;
    int mx = max(h, l);
    int mi = min(h, l);
    for (auto &i : a) {
        cin >> i;
        if (i > mx) {
            cnt++;
        }
        if (i <= mi) {
            cnt2++;
        }
    }
    cout << min((n - cnt) / 2, cnt2) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}