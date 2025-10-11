#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;  
const int M = N << 1;

int n, u, v;
int centroid[2];
int sz[N];
int head[N], to[M], nxt[M], tot;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); }
    return x * f;
}

inline void add(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    int max_sz = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > max_sz) max_sz = sz[v];
    }
    if (n - sz[u] > max_sz) max_sz = n - sz[u];
    if (max_sz <= n / 2) {
        if (centroid[0] == 0) centroid[0] = u;
        else centroid[1] = u;
    }
}

int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        u = read(); v = read();
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);

    if (centroid[1] == 0) {
        printf("%d\n", centroid[0]);
    } else {
        if (centroid[0] > centroid[1]) swap(centroid[0], centroid[1]);
        printf("%d %d\n", centroid[0], centroid[1]);
    }

    return 0;
}
