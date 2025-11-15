#include <bits/stdc++.h>

using namespace std;


int n;
vector<int> vis;
vector<int> ask() {
    vector<int> v;
    cout << "? ";
    for (int i = 1; i <= n * n + 1; i++) {
        if (!vis[i]) v.push_back(i);
    }
    cout << v.size();
    for (auto &i : v) cout << " " << i;
    cout << endl;
    int kk;
    cin >> kk;
    vector<int> res(kk);
    for (auto &x : res) cin >> x;
    return res;
}

void out(vector<int> &v) {
    cout << "! ";
    for (auto &x : v) cout << x << " ";
    cout << endl;
}

void solve() {
    
    cin >> n;
    vector<int> inc(n * n + 3);
    vector<int> nxt(n * n + 3);
    vector<int> last(n * n + 3);
    vector<int> dec(n * n + 3, 1);
    vector<int> ans(n + 1);
    vis.assign(n * n + 3, 0);
    while (1) {
        vector<int> res = ask();
        for (int i = 0; i < res.size(); i++) {
            // 递减
            if (i == res.size() - 1) {
                for (int k = res[i] + 1; k <= n * n + 1; k++) {
                    if (vis[k]) continue;
                    if (dec[k] < dec[res[i]] + 1) {
                        dec[k] = dec[res[i]] + 1;
                        last[k] = res[i];
                        if (dec[k] >= n + 1) {
                            int kk = res[i] + 1;
                            for (int j = 0; j < n + 1; j++) {
                                ans[j] = kk;
                                kk = last[kk];
                            }
                            reverse(ans.begin(), ans.end());
                            out(ans);
                            return;
                        }
                    }
                }
            } else {
                for (int k = res[i] + 1; k < res[i + 1]; k++) {
                    if (vis[k]) continue;
                    if (dec[k] < dec[res[i]] + 1) {
                        dec[k] = dec[res[i]] + 1;
                        last[k] = res[i];
                        if (dec[k] >= n + 1) {
                            int kk = res[i] + 1;
                            for (int j = 0; j < n + 1; j++) {
                                ans[j] = kk;
                                kk = last[kk];
                            }
                            reverse(ans.begin(), ans.end());
                            out(ans);
                            return;
                        }
                    }
                }
            }
            
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            if (i == 0) {
                inc[res[i]] = max(inc[res[i]], 1);
            } else {
                if (inc[res[i]] < inc[res[i - 1]] + 1) {
                    inc[res[i]] = inc[res[i - 1]] + 1;
                    nxt[res[i]] = res[i - 1];
                }
            }
            if (inc[res[i]] >= n + 1) {
                int k = res[i];
                for (int j = 0; j < n + 1; j++) {
                    ans[j] = k;
                    k = nxt[k];
                }
                out(ans);
                return;
            }
        }
        for (auto &x : res) vis[x] = 1;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}