#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[200005], a[200005], d[200005];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int T, x, n, k, y;
	cin>>T;
	while(T--) {
		cin>>n>>k;
		deque<pair<int,int> > q;
		for(int i = 1; i <= n; i++) {
			cin>>x;
			q.push_back({x, i});
		}
		memset(a + 1, 0, sizeof(int) * n);
		memset(ans + 1, 0, sizeof(int) * n);
		memset(d + 1, 0, sizeof(int) * n);
		if(k <= 6 * n) {
			for(int i = 1; i <= k; i++) {
				ans[q[0].second]++;
				ans[q[1].second]++;
				if(q[0].first > q[1].first && a[q[0].second] < n - 1) swap(q[0], q[1]);
				a[q[0].second] = 0;
				q.push_back(q[0]);
				q.pop_front();
				a[q[0].second]++;
			}	
		}else {
			x = (k - 6 * n) % (2 * n - 2);
			y = (k - 6 * n) / (2 * n - 2);
			for(int i = 1; i <= 6 * n + x; i++) {
				ans[q[0].second]++;
				ans[q[1].second]++;
				if(i > 4 * n + 2 && i <= 6 * n) {
					d[q[0].second]++;
					d[q[1].second]++;
				}
				if(q[0].first > q[1].first && a[q[0].second] < n - 1) swap(q[0], q[1]);
				a[q[0].second] = 0;
				q.push_back(q[0]);
				q.pop_front();
				a[q[0].second]++;
			}
			for(int i = 1; i <= n; i++) ans[i] += d[i] * y;
		}
		for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
} 