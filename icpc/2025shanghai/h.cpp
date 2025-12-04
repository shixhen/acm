#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int sum = max({x, y, z});
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= sum; i++) {
        int j = max(0, (x - i + 1) / 2);
        int k = max(0, (y - i + 1) / 2);
        int add = (x + y + z - 2 * i - 2 * j - 2 * k + 1) / 2;
        add = max(0, add);
        add *= min({a, b, c});
        ans = min(ans, i * b + j * a + k * c + add);
        //cout << i << " " << ans << "\n";
    }
    cout << ans << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}