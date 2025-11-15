#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;

int n, m;

int t[N][28];
int r[N], v[N];
vector<int> pre[N];
int cnt;

void insert(string &s, int idx) {
    int now = 0;
    for (auto &c : s) {
        int k = c - 'a';
        if (!t[now][k]) t[now][k] = ++cnt;
        now = t[now][k];
        pre[now].push_back(idx);
    }
}

int find(string &s) {
    int now = 0;
    for (auto &c : s) {
        int k = c - 'a';
        if (!t[now][k]) return 0;
        now = t[now][k];
    }
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> v[i];
        cin >> s;
        insert(s, i);
    }
    for (int i = 1; i <= m; i++) {
        int t;
        string s;
        cin >> t >> s;
        long long k = find(s);
        long long ans = 0;
        for (auto &x : pre[k]) {
            if (r[x] <= t) ans += v[x];
        }
        cout << ans << "\n";
    }
    return 0;
}
