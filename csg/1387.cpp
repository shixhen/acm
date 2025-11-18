#include <bits/stdc++.h>
using namespace std;

// 二叉树节点结构体
struct Node {
    char v;
    Node* l;
    Node* r;
    Node(char _v) : v(_v), l(nullptr), r(nullptr) {}
};

// 使用先序遍历字符串构建二叉树，'#' 表示空节点
Node* build(const string& s, int& i) {
    // 到达末尾或遇到 '#' 则返回空指针
    if (i >= s.size() || s[i] == '#') {
        i++;
        return nullptr;
    }
    // 构造当前节点
    Node* p = new Node(s[i++]);
    // 递归构建左子树和右子树
    p->l = build(s, i);
    p->r = build(s, i);
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int pos = 0;
        // 构建二叉树
        Node* root = build(s, pos);

        // 收集所有节点标签并排序去重
        vector<char> labels;
        function<void(Node*)> dfs = [&](Node* u) {
            if (!u) return;
            labels.push_back(u->v);
            dfs(u->l);
            dfs(u->r);
        };
        dfs(root);
        sort(labels.begin(), labels.end());
        labels.erase(unique(labels.begin(), labels.end()), labels.end());

        int n = labels.size();
        unordered_map<char, int> idx;
        for (int i = 0; i < n; i++) {
            idx[labels[i]] = i;
        }

        // 构建邻接表，便于计算距离
        vector<vector<int>> adj(n);
        function<void(Node*)> buildAdj = [&](Node* u) {
            if (!u) return;
            int uidx = idx[u->v];
            if (u->l) {
                int li = idx[u->l->v];
                adj[uidx].push_back(li);
                adj[li].push_back(uidx);
            }
            if (u->r) {
                int ri = idx[u->r->v];
                adj[uidx].push_back(ri);
                adj[ri].push_back(uidx);
            }
            buildAdj(u->l);
            buildAdj(u->r);
        };
        buildAdj(root);
        // 通过两次BFS求树的直径
        auto bfs_far = [&](int start){
            vector<int> d(n, -1);
            queue<int> q;
            q.push(start);
            d[start] = 0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: adj[u]) if(d[v]==-1){ d[v]=d[u]+1; q.push(v); }
            }
            // 找到最大距离，并收集所有对应节点
            int maxd = 0;
            for(int i=0;i<n;i++) maxd = max(maxd, d[i]);
            vector<int> far;
            for(int i=0;i<n;i++) if(d[i]==maxd) far.push_back(i);
            return make_pair(maxd, far);
        };
        // 第一次BFS从labels[0]任意节点
        auto [d1, far1] = bfs_far(0);
        // 取lex最小的A
        int A = *min_element(far1.begin(), far1.end());
        // 第二次BFS从A
        auto [bestD, far2] = bfs_far(A);
        // 取lex最小的B
        int B = *min_element(far2.begin(), far2.end());
        char uans = labels[A], vans = labels[B];
        // 排序输出字典序
        if(uans>vans) swap(uans, vans);

        // 输出结果：距离:节点1 节点2
        cout << bestD << ':';
        if (bestD > 0) cout << uans << ' ' << vans;
        cout << '\n';

        // 释放二叉树内存
        function<void(Node*)> del = [&](Node* u) {
            if (!u) return;
            del(u->l);
            del(u->r);
            delete u;
        };
        del(root);
    }
    return 0;
}