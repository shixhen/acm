#include <bits/stdc++.h>

using namespace std;

static inline bool can_pair(char l, char r) {
	return (l == '(' && r == ')') ||
		   (l == '[' && r == ']') ||
		   (l == '{' && r == '}');
}

static inline int score(char c) {
	if (c == '(' || c == ')') return 1;
	if (c == '[' || c == ']') return 2;
	return 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	while (cin >> s) {
		int n = (int)s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			dp[i][i] = score(s[i]);
		}

		for (int len = 2; len <= n; len++) {
			for (int l = 0; l + len - 1 < n; l++) {
				int r = l + len - 1;

				int best = score(s[l]) - dp[l + 1][r];
				best = max(best, score(s[r]) - dp[l][r - 1]);

				if (can_pair(s[l], s[r])) {
					int middle = (l + 1 <= r - 1) ? dp[l + 1][r - 1] : 0;
					best = max(best, score(s[l]) + score(s[r]) - middle);
				}

				dp[l][r] = best;
			}
		}

		int diff = dp[0][n - 1];
		if (diff > 0) {
			cout << "Xiao Ming Win\n";
		} else if (diff < 0) {
			cout << "Xiao Hong Win\n";
		} else {
			cout << "Draw\n";
		}
	}

	return 0;
}
