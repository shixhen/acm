#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, m;
    cin >> k >> m;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    q.push(1);
    string s = "";
    int cnt = 0;
    long long now;
    for (int i = 1; i <= k; i++) {
        now = q.top();
        s += to_string(now);
        q.pop();
        q.push(now * 2 + 1);
        q.push(now * 4 + 5);
    }
    cout << s << '\n';
    int t = 0;
    while (t < m) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] < s[i + 1]) {
                s.erase(i, 1);
                t++;
                break;
            }
        }
        if (t >= m) break;
    }
    cout << s;
    return 0;
}