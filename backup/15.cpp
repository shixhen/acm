#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> w = {0, 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5};
    vector<int> stk(w.size());
    vector<int> ls(w.size()), rs(w.size());
    int top = 0;
    int k;
    for (int i = 1; i < (int) w.size(); i++) {
        k = top;
        while (k > 0 && w[stk[k]] < w[i]) k--;
        if (k) rs[stk[k]] = i;
        if (k < top) ls[i] = stk[k + 1];
        if (k == 0) cout << w[i] << endl;
        stk[++k] = i;
        top = k;
    }
    for (int i = 1; i < (int)w.size(); i++) {
        cout << ls[i] << " " << rs[i] << "\n";
    }
    return 0;
}