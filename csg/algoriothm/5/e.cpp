
#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1000000007LL;

int idx3(int g, int p1, int p2, int n) {
	return (g * (n + 1) + p1) * (n + 1) + p2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> ends(n + 1);
		for (int i = 0; i < m; ++i) {
			int l, r;
			cin >> l >> r;
			ends[r].push_back(l);
		}

		vector<vector<int>> req(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; ++i) {
			for (int g = 0; g <= i; ++g) {
				int best = 0;
				for (int l : ends[i]) {
					if (l > g && l > best) best = l;
				}
				req[i][g] = best;
			}
		}

		int S = (n + 1) * (n + 1) * (n + 1);
		vector<long long> dp(S, 0), ndp(S, 0);
		dp[idx3(0, 0, 0, n)] = 1;

		for (int i = 1; i <= n; ++i) {
			fill(ndp.begin(), ndp.end(), 0);
			for (int g = 0; g <= i - 1; ++g) {
				for (int p1 = 0; p1 <= i - 1; ++p1) {
					for (int p2 = 0; p2 <= i - 1; ++p2) {
						long long val = dp[idx3(g, p1, p2, n)];
						if (!val) continue;
						{
							int ng = i, np1 = 0, np2 = 0;
							if (np2 >= req[i][ng]) {
								int id = idx3(ng, np1, np2, n);
								ndp[id] = (ndp[id] + val * 2) % mod;
							}
						}

						{
							int ng = g;
							int np1 = i;
							int np2 = (p1 == 0 ? 0 : p1);
							if (np2 >= req[i][ng]) {
								int id = idx3(ng, np1, np2, n);
								ndp[id] = (ndp[id] + val * 2) % mod;
							}
						}

						{
							int ng = g, np1 = p1, np2 = p2;
							if (np2 >= req[i][ng]) {
								int id = idx3(ng, np1, np2, n);
								ndp[id] = (ndp[id] + val * 6) % mod;
							}
						}
					}
				}
			}
			dp.swap(ndp);
		}

		long long ans = 0;
		for (long long v : dp) {
			ans += v;
			if (ans >= mod) ans -= mod;
		}
		cout << ans % mod << "\n";
	}

	return 0;
}
