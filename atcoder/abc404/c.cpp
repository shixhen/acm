#include <bits/stdc++.h>

using namespace std;

int f[200005];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    if (n != m) {
        cout << "No";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    int a;
    int b;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a;
        cnt[a]++;
        cin >> b;
        cnt[b]++;
        a = find(a);
        b = find(b);
        f[a] = b;
    }
    int r = find(1);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 2 || find(i) != r) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}