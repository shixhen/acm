#include <bits/stdc++.h>

using namespace std;

struct Node {
    int l;
    int r;
} node[1000005];

bool f[1000005];

int ans;
void d(int x, int num) {
    queue<pair<int, int>> q;
    q.push({x, num});
    while(q.size()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        ans = max(ans, cnt);
        if (node[now].l) {
            q.push({node[now].l, cnt + 1});
        }
        if (node[now].r) {
            q.push({node[now].r, cnt + 1});
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        f[a] = true;
        f[b] = true;
        node[i].l = a;
        node[i].r = b;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == false) {
            d(i, 1);
            break;
        }
    }
    cout << ans;
    return 0;
}