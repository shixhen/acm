#include <bits/stdc++.h>

using namespace std;

struct State {
	long long k;
	int gain;
	long long val;
};

static vector<int> build_primes(int limit) {
	vector<int> primes;
	vector<bool> is_prime(limit + 1, true);
	is_prime[0] = false;
	if (limit >= 1) is_prime[1] = false;
	for (int i = 2; i <= limit; i++) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
		if ((long long)i * i > limit) continue;
		for (int j = i * i; j <= limit; j += i) {
			is_prime[j] = false;
		}
	}
	return primes;
}

void solve_one(const vector<int>& small_primes) {
	int n;
	cin >> n;

	vector<long long> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector<long long> g(n + 1, 0);
	for (int i = 1; i < n; i++) {
		g[i] = std::gcd(a[i], a[i + 1]);
	}

	vector<long long> L(n + 1, 1);
	L[1] = g[1];
	L[n] = g[n - 1];
	for (int i = 2; i <= n - 1; i++) {
		long long x = g[i - 1], y = g[i];
		long long z = std::gcd(x, y);
		L[i] = (x / z) * y;
	}

	vector<long long> r(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		r[i] = a[i] / L[i];
	}

	const int PRIME_CAND_LIMIT = 35;
	vector<vector<State>> states(n + 1);

	for (int i = 1; i <= n; i++) {
		auto add_state = [&](long long k, int gain) {
			for (const auto& s : states[i]) {
				if (s.k == k) return;
			}
			states[i].push_back(State{k, gain, L[i] * k});
		};

		// Keep original value (always valid).
		add_state(r[i], 0);

		// C1-style free decrease to L_i when it performs an operation.
		if (r[i] > 1 && b[i] >= L[i]) {
			add_state(1, 1);
		}

		// Hard part: when a_i = L_i, we may need to increase by a prime factor.
		if (r[i] == 1) {
			long long max_mul = b[i] / L[i];
			if (max_mul >= 2) {
				long long ban_left = 1;
				long long ban_right = 1;
				if (i > 1) {
					ban_left = L[i - 1] / g[i - 1];
				}
				if (i < n) {
					ban_right = L[i + 1] / g[i];
				}

				int taken = 0;
				for (int p : small_primes) {
					if ((long long)p > max_mul) break;
					if (ban_left % p == 0) continue;
					if (ban_right % p == 0) continue;
					add_state(p, 1);
					taken++;
					if (taken >= PRIME_CAND_LIMIT) break;
				}
			}
		}
	}

	const int NEG = -1e9;
	vector<int> dp_prev(states[1].size(), NEG);
	for (int s = 0; s < (int)states[1].size(); s++) {
		dp_prev[s] = states[1][s].gain;
	}

	for (int i = 2; i <= n; i++) {
		vector<int> dp_cur(states[i].size(), NEG);
		for (int cur = 0; cur < (int)states[i].size(); cur++) {
			long long cur_val = states[i][cur].val;
			int cur_gain = states[i][cur].gain;
			int best = NEG;
			for (int prv = 0; prv < (int)states[i - 1].size(); prv++) {
				if (dp_prev[prv] == NEG) continue;
				if (std::gcd(states[i - 1][prv].val, cur_val) == g[i - 1]) {
					best = max(best, dp_prev[prv] + cur_gain);
				}
			}
			dp_cur[cur] = best;
		}
		dp_prev.swap(dp_cur);
	}

	int ans = 0;
	for (int v : dp_prev) ans = max(ans, v);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Enough small primes so that after excluding forbidden ones, we can still
	// keep a robust candidate set per position.
	vector<int> small_primes = build_primes(1000);

	int t;
	cin >> t;
	while (t--) {
		solve_one(small_primes);
	}
	return 0;
}
