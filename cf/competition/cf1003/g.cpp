#include <bits/stdc++.h>

using namespace std;

int a[200005] = {0};

bool check(int x) {
    if (x == 2 || x == 3) return true;
    if (x % 3 == 0 || x % 2 == 0 || x == 1 || x == 0) return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

int d(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (check(i) && check(x / i)) return i;
            return 0;
        }
    }
    return 0;
}
void solve() {
    int n, _;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> _;
        a[_]++;
    }
    long long psum = 0, ans = 0;
    int t;
    vector<long long> p;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) continue;
        t = d(i); 
        if (check(i)) {
            psum += a[i];
            p.push_back(a[i]);
        }
        else if (t) {
            ans += a[t] * a[i];
            ans += (long long) a[i] * (a[i] + 1) / 2;
            if (t * t != i) ans += a[i / t] * a[i]; 
        }
    }
    long long sum = 0;
    for (int i = 0; i < p.size(); i++) {
        sum += (psum - p[i]) * p[i]; 
    }
    ans += sum / 2;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL); 
    int t;
    cin >> t;
   
    while(t--) solve();
    return 0;
}