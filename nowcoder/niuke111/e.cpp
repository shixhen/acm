#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int maxn = m - k;
    int minn = 1 + k;
    if (maxn < minn) {
        swap(maxn, minn);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        auto minit = lower_bound(a.begin(), a.end(), minn);
        if (minit == a.end()) continue;
        auto maxit = upper_bound(a.begin(), a.end(), maxn);
        --maxit;
        int d = maxit - minit;
        d++;

    }
    
}