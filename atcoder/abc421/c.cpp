#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int p1 = 0;
    int p2 = 1;
    vector<pair<long long, long long>> a(2 * n);
    
    for (long long i = 0; i < 2 * n; i++) {
        if (s[i] == 'A') {
            a[i].first = p1;
            a[i].second = i;
            p1 += 2;
        } else {
            a[i].first = p2;
            a[i].second = i;
            p2 += 2;
        }
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        ans += abs(a[i].second - i);
    }

    vector<pair<long long, long long>> b(2 * n);
    p1 = 1;
    p2 = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'A') {
            b[i].first = p1;
            b[i].second = i;
            p1 += 2;
        } else {
            b[i].first = p2;
            b[i].second = i;
            p2 += 2;
        }
    }
    sort(b.begin(), b.end());
    long long ans2 = 0;
    for (long long i = 0; i < 2 * n; i++) {
        ans2 += abs(b[i].second - i);
    }
    ans = min(ans, ans2);
    cout << ans / 2;
    return 0;
}