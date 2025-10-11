#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

// Dijkstra that returns (path, cost). Honors removed nodes & removed edges.
// Tie-break: smaller lexicographic path preferred when distances equal.
pair<vector<int>, ll> dijkstra_with_removed(
    int n,
    const vector<vector<pair<int,int>>>& g,
    int s, int t,
    const vector<char>& removedNode,
    const unordered_set<int>& removedEdge // encode key = u*256 + v
) {
    struct Node {
        ll d;
        vector<int> path;
        int u;
    };
    struct Cmp {
        bool operator()(Node const& a, Node const& b) const {
            if (a.d != b.d) return a.d > b.d;         // min-dist
            return a.path > b.path;                   // tie-break: lexicographic smaller
        }
    };
    priority_queue<Node, vector<Node>, Cmp> pq;
    if (removedNode[s]) return {{}, INF};
    pq.push({0, vector<int>{s}, s});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.u;
        ll d = cur.d;
        auto &path = cur.path;
        if (u == t) return {path, d};

        // expand
        if ((int)path.size() >= n) continue; // 已包含所有节点，不能再扩展
        for (auto &e : g[u]) {
            int v = e.first, w = e.second;
            if (removedNode[v]) continue;
            int key = u * 256 + v;
            if (removedEdge.find(key) != removedEdge.end()) continue;
            // 保证简单路：不重复访问当前 path 中的节点
            bool seen = false;
            for (int x : path) if (x == v) { seen = true; break; }
            if (seen) continue;
            auto np = path;
            np.push_back(v);
            pq.push({d + w, move(np), v});
        }
    }
    return {{}, INF};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, K, a, b;
    if (!(cin >> n >> m >> K >> a >> b)) return 0;

    vector<vector<pair<int,int>>> g(n+1);
    vector<vector<int>> weight(n+1, vector<int>(n+1, -1));
    for (int i = 0; i < m; ++i) {
        int u,v,l; cin >> u >> v >> l;
        g[u].push_back({v,l});
        weight[u][v] = l;
    }
    for (int u = 1; u <= n; ++u)
        sort(g[u].begin(), g[u].end(), [](auto &A, auto &B){ return A.first < B.first; });

    // A_paths: 已确定的前 t 条路径 (按顺序)
    vector<vector<int>> A_paths;
    vector<char> emptyRemovedNode(n+1, 0);
    unordered_set<int> emptyRemovedEdge;
    auto first = dijkstra_with_removed(n, g, a, b, emptyRemovedNode, emptyRemovedEdge);
    if (first.second == INF) { cout << "No\n"; return 0; }
    A_paths.push_back(first.first);
    if (K == 1) {
        for (size_t i = 0; i < A_paths[0].size(); ++i) {
            if (i) cout << '-';
            cout << A_paths[0][i];
        }
        cout << '\n';
        return 0;
    }

    // 候选集合 B（按 cost, 再按 path 的字典序）
    struct Cand { ll cost; vector<int> path; };
    auto cmpCand = [](const Cand &x, const Cand &y) {
        if (x.cost != y.cost) return x.cost < y.cost;
        return x.path < y.path;
    };
    set<Cand, decltype(cmpCand)> B(cmpCand);
    set<vector<int>> inB;
    set<vector<int>> inA;
    inA.insert(A_paths[0]);

    // Yen 主循环
    for (int found = 1; found < K; ++found) {
        const auto &prev = A_paths.back();
        int L = (int)prev.size();
        // 预算 prefix cost，方便合并
        vector<ll> prefix(L, 0);
        for (int i = 1; i < L; ++i) prefix[i] = prefix[i-1] + weight[prev[i-1]][prev[i]];

        // 对 prev 的每个分割点作为 root
        for (int i = 0; i <= L - 2; ++i) {
            int spur = prev[i];
            vector<int> root(prev.begin(), prev.begin() + i + 1);
            ll rootCost = prefix[i];

            // 构造 removed set
            vector<char> removedNode(n+1, 0);
            for (int j = 0; j < i; ++j) removedNode[root[j]] = 1; // 删除 root 中除了 spur 的节点

            unordered_set<int> removedEdge;
            // 对所有已找到的路径，若以 root 为前缀，则删除其在该位置的下一条边
            for (auto &p : A_paths) {
                if ((int)p.size() > i) {
                    bool match = true;
                    for (int j = 0; j <= i; ++j) if (p[j] != root[j]) { match = false; break; }
                    if (match) {
                        int u = p[i], v = p[i+1];
                        removedEdge.insert(u * 256 + v);
                    }
                }
            }

            // 在修改后的图上从 spur -> b 找最短（并保持字典序 tie-break）
            auto spurRes = dijkstra_with_removed(n, g, spur, b, removedNode, removedEdge);
            if (spurRes.second == INF) continue;

            // 合并完整路径
            vector<int> total = root;
            auto &spurPath = spurRes.first;
            for (size_t t = 1; t < spurPath.size(); ++t) total.push_back(spurPath[t]);
            ll totalCost = rootCost + spurRes.second;

            if (inA.count(total)) continue;
            if (inB.count(total)) continue;
            B.insert(Cand{totalCost, total});
            inB.insert(total);
        } // end for each split

        if (B.empty()) break; // 没有更多候选

        // 取最小候选作为下一条
        auto it = B.begin();
        auto chosen = *it;
        B.erase(it);
        inB.erase(chosen.path);
        A_paths.push_back(chosen.path);
        inA.insert(chosen.path);

        if ((int)A_paths.size() == K) {
            auto &ans = A_paths.back();
            for (size_t i = 0; i < ans.size(); ++i) {
                if (i) cout << '-';
                cout << ans[i];
            }
            cout << '\n';
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
