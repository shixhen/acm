#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;

int idx[N]; // 每个模式串对应的编号
int ans[N];
int tot = 0, pidx = 0;

struct AC_node {
    int son[26];
    int fail;
    int du;   // 入度
    int idx;  // 以该节点结尾的模式串的编号
    int cnt;  // 匹配到的数量
    AC_node() : fail(0), du(0), idx(0), cnt(0) { memset(son, 0, sizeof(son)); }
} trie[N];


void insert(const string& s, int &idx) {
    int u = 0;
    for (auto &c : s) {
        int k = c - 'a';
        if (!trie[u].son[k]) trie[u].son[k] = ++tot;
        u = trie[u].son[k];
    }
    if (!trie[u].idx) trie[u].idx = ++pidx;
    idx = trie[u].idx;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0].son[i]) {
            trie[trie[0].son[i]].fail = 0;
            q.push(trie[0].son[i]);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            int &v = trie[u].son[i];
            if (v) {
                trie[v].fail = trie[trie[u].fail].son[i];
                trie[trie[v].fail].du++;
                q.push(v);
            } else {
                v = trie[trie[u].fail].son[i];
            }
        }
    }
}

void query(const string &s) {
    int u = 0;
    for (auto &c : s) {
        u = trie[u].son[c - 'a'];
        trie[u].cnt++;
    }
}

void topo() {
    queue<int> q;
    for (int i = 1; i <= tot; i++) {
        if (trie[i].du == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int f = trie[u].fail;
        trie[f].cnt += trie[u].cnt;
        if (--trie[f].du == 0) q.push(f);
    }
    for (int i = 1; i <= tot; i++) {
        if (trie[i].idx) {
            ans[trie[i].idx] = trie[i].cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert(s, idx[i]);
    }
    build();
    string t;
    cin >> t;
    query(t);
    topo();
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += (ans[idx[i]] != 0);
    }
    cout << res << "\n";
    return 0;
}