#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long x;
    cin >> x;
    set<long long> ans;
    long long k;
    ans.insert((-x));
    for (long long i = 0; i <= 1e7; i++) {
        if ((x - (i * i)) % (2ll * i - 1ll) == 0) {
            k = (x - (i * i)) / (2ll * i - 1ll);
            ans.insert(k);
        }
        if ((x - (i * i)) % ((2ll * (-i)) - 1ll) == 0) {
            k = (x - (i * i)) / ((2ll * (-i)) - 1ll);
            ans.insert(k);
        }
    }
    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i << " ";
    }
    return 0;
}