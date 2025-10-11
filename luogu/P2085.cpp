#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005], c[100005];

struct Node{
    int ans;
    int idx;
    int x;
    bool operator <(const Node &other) const {
        return ans > other.ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    priority_queue<Node> q;
    for (int i = 1; i <= n; i++) {
        Node node;
        node.ans = a[i] + b[i] + c[i];
        node.idx = i;
        node.x = 1;
        q.push(node);
    }
    for (int i = 1; i <= m; i++) {
        Node now = q.top();
        q.pop();
        cout << now.ans << ' ';
        now.x++;
        now.ans = now.x * now.x * a[now.idx] + now.x * b[now.idx] + c[now.idx];
        q.push(now);
    }
    return 0;
}