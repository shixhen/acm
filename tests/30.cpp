#include <bits/stdc++.h>
using namespace std;

struct NodeData {
    vector<int> arr;                // arr for this node (values for each allowed cut depth)
    unordered_map<int,int> cnt;     // counts of values in arr, for mex
    int grundy = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        vector<vector<int>> children(n+1);
        vector<int> roots;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            if (p[i] == 0) roots.push_back(i);
            else children[p[i]].push_back(i);
        }

        // Build a postorder (nodes in bottom-up order) iteratively for each root.
        vector<int> order;
        order.reserve(n);
        for (int r : roots) {
            // iterative DFS to collect nodes in preorder then we'll reverse
            vector<int> st;
            st.push_back(r);
            while (!st.empty()) {
                int v = st.back(); st.pop_back();
                order.push_back(v);
                for (int c : children[v]) st.push_back(c);
            }
        }
        // reverse to get postorder (children before parent)
        reverse(order.begin(), order.end());

        // container to store each node's data
        vector<NodeData> data(n+1);

        // process nodes in postorder
        for (int v : order) {
            if (children[v].empty()) {
                // leaf
                data[v].arr = {0};
                data[v].cnt.clear();
                data[v].cnt[0] = 1;
                // mex of {0} is 1
                data[v].grundy = 1;
            } else if (children[v].size() == 1) {
                int c = children[v][0];
                // move child's arrays to parent and append child's grundy
                data[v].arr = std::move(data[c].arr);
                data[v].cnt = std::move(data[c].cnt);
                int g = data[c].grundy;
                data[v].arr.push_back(g);
                data[v].cnt[g] += 1;
                // compute mex
                int mex = 0;
                while (data[v].cnt.find(mex) != data[v].cnt.end()) ++mex;
                data[v].grundy = mex;
            } else {
                // multiple children
                // pick child with minimal arr.size()
                int best = children[v][0];
                for (int c : children[v]) {
                    if (data[c].arr.size() < data[best].arr.size()) best = c;
                }
                // take base by moving
                data[v].arr = std::move(data[best].arr);
                data[v].cnt = std::move(data[best].cnt);

                size_t h = data[v].arr.size(); // h = min child rank
                // for all other children, XOR their arrays into base for positions 0..h-1
                for (int c : children[v]) {
                    if (c == best) continue;
                    // child must have at least h length
                    for (size_t i = 0; i < h; ++i) {
                        int oldv = data[v].arr[i];
                        int newv = oldv ^ data[c].arr[i];
                        // update counts
                        auto it = data[v].cnt.find(oldv);
                        if (it != data[v].cnt.end()) {
                            if (--(it->second) == 0) data[v].cnt.erase(it);
                        }
                        data[v].cnt[newv] += 1;
                        data[v].arr[i] = newv;
                    }
                }
                // append XOR of children's grundy
                int xor_all = 0;
                for (int c : children[v]) xor_all ^= data[c].grundy;
                data[v].arr.push_back(xor_all);
                data[v].cnt[xor_all] += 1;

                // compute mex
                int mex = 0;
                while (data[v].cnt.find(mex) != data[v].cnt.end()) ++mex;
                data[v].grundy = mex;
            }
        }

        // XOR the grundy values of all trees (roots of forest)
        int overall_xor = 0;
        for (int r : roots) overall_xor ^= data[r].grundy;
        cout << (overall_xor ? "YES\n" : "NO\n");
    }
    return 0;
}
