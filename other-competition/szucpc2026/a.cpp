#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline int64 ceil_div(int64 a, int64 b) {
	return (a + b - 1) / b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int64 x, y, s1, s2;
		cin >> x >> y >> s1 >> s2;

		int64 a = min(s1, s2);
		int64 b = max(s1, s2);
		int64 d = b - a;

		if (d == 0) {
			// Sum is known from the start, first player wins immediately.
			cout << "Yagami\n";
			continue;
		}

		// Yagami's k-th turn is round (2k-1).
		// First decisive k:
		//   kY = min( ceil(x/d), ceil((a-x)/d) + 1 )
		int64 kY = min(ceil_div(x, d), ceil_div(a - x, d) + 1);
		int64 roundY = 2 * kY - 1;

		// L's k-th turn is round (2k).
		// First decisive k:
		//   kL = min( ceil(y/d), ceil((a-y)/d) )
		int64 kL = min(ceil_div(y, d), ceil_div(a - y, d));
		int64 roundL = 2 * kL;

		cout << (roundY < roundL ? "Yagami" : "L") << '\n';
	}

	return 0;
}
