#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    // 若相同则直接输出答案
    if (s == t) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> to(26, -1);
    // to[i] 是i最终要变的值
    for (int i = 0; i < n; i++) {
        int sc = s[i] - 'a';
        int tc = t[i] - 'a';
        // 相同的字母不能变成不同的字母
        if (to[sc] != -1 and to[sc] != tc) {
            cout << -1 << endl;
            return 0;
        }
        to[sc] = tc;
    }
    bool is_perm = true;
    vector<int> tmp = to;
    // 判断是否全都是自环
    // 若全都是自环和环，则无法达到目标
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < 26; i++) {
        is_perm &= (tmp[i] == i);
    }
    if (is_perm) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    // 每个字符的入度
    vector<int> in_deg(26);
    // 并查集
    vector<int> f(26);
    // 初始化
    for (int i = 0; i < 26; i++) {
        f[i] = i;
    }
    auto find = [&] (auto &self, int x) -> int {
        return f[x] == x ? x : f[x] = self(self, f[x]); 
    };
    auto merge = [&] (int u, int v) {
        int a = find(find, u);
        int b = find(find, v);
        if (a != b) f[a] = b;
        return;
    };
    
    for (int i = 0; i < 26; i++) {
        if (to[i] != -1) {
            if (to[i] != i) {
                ans++;
            }
            in_deg[to[i]]++;
            merge(i, to[i]);
        }
    }
    auto get_groups = [&] () {
        vector<vector<int>> g;
        vector<bool> st(26);
        vector<int> temp;
        for (int i = 0; i < 26; i++) {
            if (st[i]) continue;
            st[i] = true;
            temp.push_back(i);
            for (int j = i + 1; j < 26; j++) {
                if (st[j]) continue;
                if (find(find, f[j]) == find(find, f[i])) {
                    st[j] = true;
                    temp.push_back(j);
                }
            }
            g.push_back(temp);
            temp.clear();
        }
        return g;
    };
    vector<vector<int>> groups = get_groups();
    for (const vector<int> &g: groups) {
        bool is_cycle = true;
        // 判断是否成环，每个环需要加一
        for (int i: g) {
            is_cycle &= (in_deg[i] == 1);
        }
        if (is_cycle and g.size() > 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
