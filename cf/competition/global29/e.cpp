#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        long long cur_or = 0;
        for (auto x : a) cur_or |= x;
        
        int base = __builtin_popcountll(cur_or);
        
        vector<long long> costs;
        for (int bit = 0; bit < 32; bit++) {
            if ((cur_or >> bit) & 1) continue; // 已有该位
            long long need = LLONG_MAX;
            for (auto x : a) {
                long long mod = x & ((1LL << bit) - 1);
                long long add = (1LL << bit) - mod;
                need = min(need, add);
            }
            costs.push_back(need);
        }
        
        sort(costs.begin(), costs.end());
        vector<long long> pref(costs.size()+1, 0);
        for (int i = 0; i < (int)costs.size(); i++)
            pref[i+1] = pref[i] + costs[i];
        
        while (q--) {
            long long b; cin >> b;
            int extra = upper_bound(pref.begin(), pref.end(), b) - pref.begin() - 1;
            cout << base + extra << "\n";
        }
    }
}
