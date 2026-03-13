#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
vector<int> adj[MAXN];
long long dp[MAXN][2]; 
vector<pair<int, int>> sol;

// 第一遍 DFS：计算 DP 值
void dfs_calc(int u, int p) {
    long long sum_val = 0;
    int k = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_calc(v, u);
        sum_val += dp[v][1];
        k++;
    }
    if (k == 0) dp[u][0] = sum_val + 1;
    else dp[u][0] = sum_val + (k + 1) / 2;
    dp[u][1] = sum_val + k / 2;
}

// 辅助函数：将 u 的所有子节点的“可用端点”收集上来
// state 表示 u 此时是处于 dp[u][0] (limit=0) 还是 dp[u][1] (limit=1)
// limit: 表示允许向上传递（或剩余）多少个端点。
//        state 0 -> limit 0 (不传给父亲)
//        state 1 -> limit 1 (传给父亲 1 个)
// 返回值：该子树向上传递的端点编号 (如果 limit=0 则返回 0)
int dfs_build(int u, int p, int limit) {
    vector<int> ends;
    
    // 递归获取所有子节点提供的端点
    // 注意：既然我们在计算时默认子节点都选了 state 1 (连接)，
    // 那么构建时我们也要求子节点返回它们的端点。
    for (int v : adj[u]) {
        if (v == p) continue;
        // 子节点必须以 state 1 参与（即提供一个端点给 u）
        int e = dfs_build(v, u, 1); 
        ends.push_back(e);
    }

    // 现在我们在 u 处有 ends.size() 个端点
    // 我们需要配对
    int k = ends.size();
    int rem = 0; // 最终返回给父亲的端点

    // 如果 limit == 1 (state 1)，我们需要留一个给父亲，其他的配对
    // 如果 limit == 0 (state 0)，我们全部内部消化
    
    if (limit == 1) {
        // 既然父亲要一个，我们留哪一个？其实留任何一个都行。
        // 为了方便，我们留最后一个。
        // 但如果 k=0 (叶子且 state 1)，它自己就是端点。
        if (k == 0) {
            return u; 
        } else {
            // 留下 ends.back() 给父亲
            rem = ends.back();
            ends.pop_back();
            // 剩下的 k-1 个两两配对
        }
    } else { // limit == 0
        // 全部配对
        // 如果 k=0 (叶子且 state 0)，它是孤立路径
        if (k == 0) {
            // 自己连自己（或者题目里的单点激活）
            // 这里的路径定义可以是一个点吗？
            // 题目说 "path... between two stations". 
            // 实际上对于孤立点，我们随便连一条边通常不优，或者它就是单独的。
            // 我们的 DP 逻辑对 k=0 记了 1。这通常意味着一条以 u 为起点的路径，
            // 但没有终点？不，这代表 u 是某条路径的一端，另一端在...它自己？
            // 其实这在 N=1 时发生。N>=2 时，state 0 的叶子实际上不会发生，
            // 因为 DP 决策里我们总是贪心连所有子节点。
            // 唯一可能发生 state 0 的情况是根节点。
            // 根节点 k=0? 只有 N=1。
            // 根节点 k>0?
        }
        // 如果 k 是奇数且 limit=0？
        // DP 公式里 (k+1)/2。比如 k=1 -> 1 条路。
        // 这意味着这 1 个端点在 u 终结。
        // 比如 1-2-3。2是根。左边上来1，右边上来3。ends={1,3}。
        // 配对 (1,3)。
        // 如果 k=1。ends={1}。2是根。
        // 那么路径就是 1-2。
        // 所以，如果剩下奇数个，最后那个和 u 连。
    }

    // 执行配对
    for (size_t i = 0; i + 1 < ends.size(); i += 2) {
        sol.push_back({ends[i], ends[i+1]});
    }

    // 处理剩下的那个（如果有）
    if (ends.size() % 2 == 1) {
        // 剩下一个没法和兄弟配对，只能和 u 终结
        sol.push_back({ends.back(), u});
    }

    return rem;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    for(int i=1;i<=n;i++) adj[i].clear();
    sol.clear();
    for(int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    
    dfs_calc(1, -1);
    
    // 构建路径，根节点必须是 state 0 (limit 0)
    dfs_build(1, -1, 0);

    cout << sol.size() << "\n";
    for(auto &p : sol) cout << p.first << " " << p.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(cin >> t) while(t--) solve();
    return 0;
}