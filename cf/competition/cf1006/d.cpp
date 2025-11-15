#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxn = 0;
    int ans_l = 0;
    int ans_r = 0;
    vector<int> cnt(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) cnt[j]--;
            if (a[j] > a[i]) cnt[j]++;
            if (maxn < cnt[j]) {
                ans_l = j;
                ans_r = i;
                maxn = cnt[j];
            }
        }
        
    }
    cout << ans_l + 1 << " " << ans_r + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}