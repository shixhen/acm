#include <bits/stdc++.h>

using namespace std;

long long get_hash(const string &s) {
    long long hash = 0;
    for (char c : s) {
        hash = hash * 131 + c;
    }
    return hash;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<long long> hashes(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        hashes[i] = get_hash(s);
    }
    sort(hashes.begin(), hashes.end());
    int ans = unique(hashes.begin(), hashes.end()) - hashes.begin();
    cout << ans << "\n";
    return 0;
}