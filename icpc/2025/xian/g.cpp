#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int ans_max = 0;
    int ans_min = 0;
    for (int i = 0; i < n; i++) {
        if (ans_max >= a[i]) {
            ans_max++;
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (ans_min < a[i]) {
            ans_min--;
        } else {
            break;
        }
    }
    cout << ans_max << " " << ans_min << "\n";
    return 0;
}