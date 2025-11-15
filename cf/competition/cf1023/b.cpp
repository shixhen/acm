#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (auto &i: a){
        cin >> i;
        sum += i;
    }
    long long maxn = *max_element(a.begin(), a.end());
    long long minn = *min_element(a.begin(), a.end());
    long long cnt = 0;
    for (auto i: a) {
        if (i - minn > k) {
            cnt += i - minn - k;
        }
    }
    if (cnt > 1) {
        cout << "Jerry\n";
    } else if (sum % 2ll) {
        cout << "Tom\n";
    } else cout << "Jerry\n";
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