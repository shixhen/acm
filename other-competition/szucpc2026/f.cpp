#include <bits/stdc++.h>
using namespace std;

struct Operation {
	int type;
	int x;
	int y;
	int z;
};

struct Block {
	int l = 0;
	int r = 0;
	int leafCnt = 0;
	int nonLeafCnt = 0;

	bool lazy = true;
	int tagLeaf = 0;
	int tagNonLeaf = 0;

	vector<int> val;
	unordered_map<int, int> freq;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, q;
		cin >> n >> q;

		vector<vector<int>> g(n + 1);
		for (int i = 1; i <= n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<Operation> ops;
		ops.reserve(q);
		vector<int> allVals;
		allVals.reserve(2 * q + 1);
		allVals.push_back(0);

		for (int i = 0; i < q; ++i) {
			int type;
			cin >> type;
			if (type == 1) {
				int x, y, z;
				cin >> x >> y >> z;
				ops.push_back({1, x, y, z});
				allVals.push_back(y);
				allVals.push_back(z);
			} else {
				int x;
				cin >> x;
				ops.push_back({2, x, 0, 0});
				allVals.push_back(x);
			}
		}

		vector<int> tin(n + 1), tout(n + 1), euler(n + 1), childCnt(n + 1, 0);
		vector<int> parent(n + 1, 0), it(n + 1, 0);
		int timer = 0;

		vector<int> st;
		st.reserve(n);
		st.push_back(1);
		parent[1] = -1;

		while (!st.empty()) {
			int u = st.back();
			if (it[u] == 0) {
				tin[u] = ++timer;
				euler[timer] = u;
			}

			if (it[u] < static_cast<int>(g[u].size())) {
				int v = g[u][it[u]++];
				if (v == parent[u]) {
					continue;
				}
				parent[v] = u;
				++childCnt[u];
				st.push_back(v);
			} else {
				tout[u] = timer;
				st.pop_back();
			}
		}

		vector<char> isLeafNode(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			isLeafNode[i] = (childCnt[i] == 0);
		}

		vector<char> isLeafPos(n + 1, 0);
		for (int pos = 1; pos <= n; ++pos) {
			isLeafPos[pos] = isLeafNode[euler[pos]];
		}

		sort(allVals.begin(), allVals.end());
		allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

		auto getId = [&](int v) {
			return static_cast<int>(lower_bound(allVals.begin(), allVals.end(), v) - allVals.begin());
		};

		int B = max(1, static_cast<int>(sqrt(n)));
		int blockCnt = (n + B - 1) / B;
		vector<int> posBlock(n + 1, 0);
		vector<Block> blocks(blockCnt);

		for (int b = 0; b < blockCnt; ++b) {
			int l = b * B + 1;
			int r = min(n, (b + 1) * B);

			blocks[b].l = l;
			blocks[b].r = r;
			blocks[b].lazy = true;
			blocks[b].tagLeaf = getId(0);
			blocks[b].tagNonLeaf = getId(0);

			for (int pos = l; pos <= r; ++pos) {
				posBlock[pos] = b;
				if (isLeafPos[pos]) {
					++blocks[b].leafCnt;
				} else {
					++blocks[b].nonLeafCnt;
				}
			}
		}

		auto materialize = [&](int b) {
			Block &blk = blocks[b];
			if (!blk.lazy) {
				return;
			}

			int len = blk.r - blk.l + 1;
			blk.val.assign(len, 0);
			blk.freq.clear();
			blk.freq.reserve(static_cast<size_t>(len * 2 + 1));

			for (int pos = blk.l; pos <= blk.r; ++pos) {
				int v = isLeafPos[pos] ? blk.tagLeaf : blk.tagNonLeaf;
				blk.val[pos - blk.l] = v;
				++blk.freq[v];
			}

			blk.lazy = false;
		};

		auto rangeAssign = [&](int L, int R, int nonLeafVal, int leafVal) {
			int bL = posBlock[L];
			int bR = posBlock[R];

			for (int b = bL; b <= bR; ++b) {
				Block &blk = blocks[b];
				if (L <= blk.l && blk.r <= R) {
					blk.lazy = true;
					blk.tagLeaf = leafVal;
					blk.tagNonLeaf = nonLeafVal;
					blk.freq.clear();
					continue;
				}

				materialize(b);
				int from = max(L, blk.l);
				int to = min(R, blk.r);
				for (int pos = from; pos <= to; ++pos) {
					int idx = pos - blk.l;
					int newVal = isLeafPos[pos] ? leafVal : nonLeafVal;
					int oldVal = blk.val[idx];
					if (oldVal == newVal) {
						continue;
					}

					auto itOld = blk.freq.find(oldVal);
					--(itOld->second);
					if (itOld->second == 0) {
						blk.freq.erase(itOld);
					}

					blk.val[idx] = newVal;
					++blk.freq[newVal];
				}
			}
		};

		auto queryCount = [&](int targetVal) {
			long long ans = 0;
			for (int b = 0; b < blockCnt; ++b) {
				const Block &blk = blocks[b];
				if (blk.lazy) {
					if (blk.tagLeaf == targetVal) {
						ans += blk.leafCnt;
					}
					if (blk.tagNonLeaf == targetVal) {
						ans += blk.nonLeafCnt;
					}
				} else {
					auto itFreq = blk.freq.find(targetVal);
					if (itFreq != blk.freq.end()) {
						ans += itFreq->second;
					}
				}
			}
			return ans;
		};

		for (const auto &op : ops) {
			if (op.type == 1) {
				int x = op.x;
				int yId = getId(op.y);
				int zId = getId(op.z);
				rangeAssign(tin[x], tout[x], yId, zId);
			} else {
				int xId = getId(op.x);
				cout << queryCount(xId) << '\n';
			}
		}
	}

	return 0;
}
