#include <bits/stdc++.h>

using namespace std;

bool is_prime(int a) {
    if (a == 2 || a == 3) return 1;
    if (a % 2 == 0 || a % 3 == 0 || a == 1) return 0;
    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) return 0;
    }
    return 1;
}
void solve() {
    int x, k;
    cin >> x >> k;
    if (k == 2 and x == 1) {
        cout << "Yes\n";
        return;
    }
    if (k > 1) {
        cout << "No\n";
        return;
    }
    if (is_prime(x)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}