#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1]= h;
    stack<int> s;
    s.push(0);
    vector<long long> pre(n + 1), suf(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            long long t = s.top();
            s.pop();
            sum -= (long long) (h - a[t]) * (t - s.top());
        }
        sum += (long long) (h - a[i]) * (i - s.top());
        s.push(i);
        pre[i] = sum;
    }
    
    while (!s.empty()) {
        s.pop();
    }
    s.push(n + 1);
    sum = 0;
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] < a[i]) {
            long long t = s.top();
            s.pop();
            sum -= (long long) (h - a[t]) * abs(t - s.top());
        }
        sum += (long long) (h - a[i]) * abs(i - s.top());
        s.push(i);
        suf[i] = sum;
    }
    vector<long long> cnt(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = pre[i] + suf[i] - (h - a[i]);
        //cout << cnt[i] << " ";
        ans = max(ans, cnt[i]);
    }
    for (int i = 1; i < n; i++) {
        int maxh = a[i];
        int maxi = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] > maxh) {
                maxh = a[j];
                maxi = j;
            }   
            ans = max(ans, cnt[i] + cnt[j] - cnt[maxi]);
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();

    }

    return 0;
}