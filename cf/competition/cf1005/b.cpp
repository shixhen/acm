#include <bits/stdc++.h>

using namespace std;

int a[200005] = {0};
int num[200005] = {0};
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        num[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    int l = 0;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        if (num[a[i]] == 1) {
            int temp = 0;
            int t = i;
            while(num[a[i]] == 1 && i <= n) {
                i++;
                temp++;
            }
            if (temp > maxn) {
                maxn = temp;
                l = t;
            }
        }
    }
    if (maxn == 0) {
        cout << 0 << '\n';
    } else {
        cout << l << " " << l + maxn - 1<< '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}