#include <bits/stdc++.h>

using namespace std;

int length(long long x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

long long ipow(long long a, long long t) {
    long long res = 1;
    while (t--) {
        res *= a;
    }
    return res;
    
}

void solve() {
    long long x;
    cin >> x;
    long long num = 10;
    for (int i = 1; i <= 9; i++) {
        if (num > x && length(num - x - 1) == i) {
            break;
        }
        num *= 10;
    }
    long long y = num - x - 1;
    cout << y << "\n";
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