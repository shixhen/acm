#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(26);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            a[s[i] - 'a']++;
        } else {
            a[s[i] - 'A']++;
        }
    }
    string t ="shanghai";
    int ans = 0x3f3f3f3f;
    for (auto x: t) {
        if (x == 'h') {
            ans = min(ans, a[x - 'a'] / 2);
        } else if (x == 'a') {
            ans = min(ans, a[x - 'a'] / 2);
        } else {
            ans = min(ans, a[x - 'a']);
        }
    }
    cout << ans << '\n';

    return 0;
}