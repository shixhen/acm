#include <bits/stdc++.h>

using namespace std;

// pattern_id[i]：第 i 个输入模式串映射到“去重后模式串编号”。
// 例如第 2 个和第 5 个模式串内容相同，则二者会映射到同一个编号。
vector<int> pattern_id;
// match_cnt[id]：去重后编号 id 对应模式串在文本串中的出现次数。
vector<int> match_cnt;
// pattern[i]：保留第 i 个输入模式串原文，按输入顺序输出答案时使用。
vector<string> pattern;
// tot：当前 Trie 已创建的最大节点编号（根节点固定为 0）。
// unique_pattern_cnt：去重后模式串总数。
int tot = 0, unique_pattern_cnt = 0;

struct ACNode {
    // son[c]：从当前节点出发，读入字符 c（0~25）后的转移节点。
    // 在 build_automaton 后，会被补全为“自动机转移”（不存在的边会指向 fail 转移结果）。
    int son[26];
    // fail：失配指针。
    int fail;
    // indeg：在 fail 树上的入度（用于拓扑回传出现次数）。
    int indeg;
    // terminal_id：若该节点是某个模式串结尾，则记录其去重后编号，否则为 0。
    int terminal_id;
    // cnt：匹配计数。
    // query_text 阶段表示“文本扫描时落在该状态的次数”；
    // propagate_count 阶段会叠加 fail 子树贡献，最终表示该状态对应串出现次数。
    int cnt;
    ACNode() : fail(0), indeg(0), terminal_id(0), cnt(0) { memset(son, 0, sizeof(son)); }
};

// AC 自动机底层节点数组，trie[0] 为根节点。
vector<ACNode> trie;

void insert_pattern(const string& s, int& id) {
    int u = 0;
    for (char c : s) {
        int k = c - 'a';
        // 动态扩容：首次走到该字符分支时创建新节点，
        // 避免使用固定容量导致的越界风险。
        if (!trie[u].son[k]) {
            trie[u].son[k] = ++tot;
            trie.emplace_back();
        }
        u = trie[u].son[k];
    }
    // 对重复模式串做去重：同一个终止节点只分配一次编号。
    if (!trie[u].terminal_id) trie[u].terminal_id = ++unique_pattern_cnt;
    id = trie[u].terminal_id;
}

void build_automaton() {
    // BFS 构建 fail 指针，并补全自动机转移。
    // 根节点缺失转移默认保留为 0（即回到根）。
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0].son[i]) {
            q.push(trie[0].son[i]);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            int &v = trie[u].son[i];
            if (v) {
                // 存在儿子边：其 fail 等于“当前节点 fail 状态在字符 i 上的转移”。
                trie[v].fail = trie[trie[u].fail].son[i];
                // 统计 fail 树入度，后面用于拓扑反向累加 cnt。
                trie[trie[v].fail].indeg++;
                q.push(v);
            } else {
                // 不存在儿子边：直接补成 fail 转移结果，形成完整 DFA 转移表。
                v = trie[trie[u].fail].son[i];
            }
        }
    }
}

void query_text(const string& s) {
    // 扫描文本串：每读一个字符就沿自动机走一步，
    // 在落点状态计数 +1。
    // 注意此时还没把 fail 链上的模式串贡献加上，后续统一在 propagate_count 中处理。
    int u = 0;
    for (char c : s) {
        u = trie[u].son[c - 'a'];
        trie[u].cnt++;
    }
}

void propagate_count() {
    // 在 fail 树上做“从叶到根”的拓扑回传：
    // 若状态 u 被访问了 cnt 次，则其 fail 状态也应额外获得 cnt 次。
    queue<int> q;
    for (int i = 1; i <= tot; i++) {
        if (trie[i].indeg == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int f = trie[u].fail;
        trie[f].cnt += trie[u].cnt;
        // 根节点不参与入度递减入队，避免对根做无意义处理。
        if (f != 0 && --trie[f].indeg == 0) q.push(f);
    }

    // 把每个终止节点的计数写回到“去重后模式串编号”上。
    for (int i = 1; i <= tot; i++) {
        if (trie[i].terminal_id) {
            match_cnt[trie[i].terminal_id] = trie[i].cnt;
        }
    }
}

void solve(int n) {
    // 每组数据重新初始化。
    tot = 0;
    unique_pattern_cnt = 0;
    trie.assign(1, ACNode());
    pattern_id.assign(n + 1, 0);
    match_cnt.assign(n + 1, 0);
    pattern.assign(n + 1, "");

    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert_pattern(s, pattern_id[i]);
        pattern[i] = s;
    }

    // 建自动机 + 扫文本 + 回传统计。
    build_automaton();

    string t;
    cin >> t;
    query_text(t);
    propagate_count();

    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, match_cnt[pattern_id[i]]);
    }
    cout << maxn << "\n";

    // 按原输入顺序输出所有出现次数等于最大值的模式串。
    // 若存在重复模式串，会按输入次数重复输出（与题意一致）。
    for (int i = 1; i <= n; i++) {
        if (match_cnt[pattern_id[i]] == maxn) cout << pattern[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // 多组数据，n=0 结束。
    while (cin >> n && n != 0) {
        solve(n);
    }
    return 0;
}