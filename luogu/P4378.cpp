#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i].second - i);
    }
    cout << ans + 1;
    return 0;
}