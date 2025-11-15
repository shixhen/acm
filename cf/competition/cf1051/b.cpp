#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<int> b(k);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    long long ans = 0;
    while (i < n) {
        if (j < k) {
            if (b[j] > n - i) {
                break;
            }
            while (b[j]) {
                if (b[j] == 1) {
                    i++;
                    break;
                }
                ans += a[i++];
                b[j]--;
            }
            j++;
        } else {
            break;
        }
    }
    while (i < n) {
        ans += a[i++];
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}