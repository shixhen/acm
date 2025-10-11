#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 5, M = 1e5 + 5;
int n, m;
int h[N], e[M], v[M], ne[M], idx;
int dis[N];
bool st[N]; // 是否在队列中
int cnt[N]; // 入队次数（检测负环）

void add(int a, int b, int c) {
    e[idx] = b;
    v[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa(int start) {
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(st, 0, sizeof(st));

    queue<int> q;
    dis[start] = 0;
    q.push(start);
    st[start] = true;
    cnt[start]++;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[u] + v[i]) {
                dis[j] = dis[u] + v[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                    cnt[j]++;
                    // 检测负环
                    if (cnt[j] > n) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa(1);
    cout << dis[n] << endl;
    return 0;
}