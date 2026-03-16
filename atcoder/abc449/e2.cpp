#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> cnt(m + 1);
    vector<vector<int>> num(n + 1);
    long long mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        mx = max(mx, (long long) cnt[i]);
        for (int j = 1; j <= cnt[i]; j++) {
            num[j].push_back(i);
            //cout << j << " " << i << endl;
        }
    }
    int q;
    cin >> q;
    vector<pair<long long, int>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].first;
        ask[i].second = i;
    }
    sort(ask.begin(), ask.end());
    long long r = 1;
    long long pre = 0;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        if (ask[i].first <= n) {
            ans[ask[i].second] = a[ask[i].first];
            continue;
        }
        if (ask[i].first > mx * m) {
            ans[ask[i].second] = (ask[i].first - 1) % m + 1;
            continue;
        }
        long long x = ask[i].first - n;
        while (x > pre + m - num[r].size()) {
            //cout << r << " " << pre << "\n";
            pre += m - num[r].size();
            r++;
        }
        x -= pre;
        int l = 1, right = m;
        int mid;
        // for (auto &v : num[r]) {
        //     cout << v << " ----\n";
        // }
        while (l <= right) {
            mid = (l + right) / 2;
            auto it = upper_bound(num[r].begin(), num[r].end(), mid);
            int deleted_count = it - num[r].begin(); 
            //cout << deleted_count << " " << mid << " " << x << "\n"; 
            int available_count = mid - deleted_count;  
        
            if (available_count < x) {
                l = mid + 1;  
            } else {
                right = mid - 1;  
            }
        }
        ans[ask[i].second] = l;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}