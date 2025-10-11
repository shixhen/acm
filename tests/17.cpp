#include <bits/stdc++.h>

using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, s, a, b;
    cin >> n;
    long long lastans = 0;
    long long sumb = 0;
    vector<long long> str(n);
    vector<long long> nxt(n);
    for (int i = 0, j = 0; i < n; i++) {
        cin >> s >> a >> b;
        str[i] = (s + lastans) % n;

    }
    return 0;
}