#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 30;
constexpr int MAX_TIME = 300;
constexpr int MAX_B_SUM = 300;
constexpr long long NEG = -(1LL << 60);

int A[MAX_N], B[MAX_N];
pair<int, int> missions[MAX_N]; // {A, B}
long long dp[MAX_TIME + 1][MAX_B_SUM + 1];

static long long solveOne(int n, int m) {
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < n; ++i) {
        missions[i] = {A[i], B[i]};
        sumA += A[i];
        sumB += B[i];
    }

    sort(missions, missions + n, [&](const auto &x, const auto &y) {
        return x.second > y.second;
    });

    int maxTime = min(m, sumA);
    int maxPick = min(n, maxTime);
    int sumBLimit = min(sumB, maxPick * 10);

    for (int t = 0; t <= maxTime; ++t) {
        for (int s = 0; s <= sumBLimit; ++s) {
            dp[t][s] = NEG;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int a = missions[i].first;
        int b = missions[i].second;
        for (int t = maxTime - a; t >= 0; --t) {
            for (int s = sumBLimit - b; s >= 0; --s) {
                if (dp[t][s] == NEG) {
                    continue;
                }
                // Only previously finished missions contribute memory at this moment.
                dp[t + a][s + b] = max(dp[t + a][s + b], dp[t][s] + s);
            }
        }
    }

    long long ans = 0;
    for (int t = 0; t <= maxTime; ++t) {
        for (int s = 0; s <= sumBLimit; ++s) {
            ans = max(ans, dp[t][s]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string firstLine;
    if (!getline(cin, firstLine)) {
        return 0;
    }
    while (firstLine.empty() && getline(cin, firstLine)) {
    }
    if (firstLine.empty()) {
        return 0;
    }

    stringstream ss(firstLine);
    vector<long long> head;
    for (long long x; ss >> x; ) {
        head.push_back(x);
    }
    if (head.empty()) {
        return 0;
    }

    auto readAndSolveOne = [&]() -> bool {
        int n, m;
        if (!(cin >> n >> m)) {
            return false;
        }
        if (n < 0 || n > MAX_N) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (!(cin >> A[i])) {
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!(cin >> B[i])) {
                return false;
            }
        }
        cout << solveOne(n, m) << "\n";
        return true;
    };

    if (head.size() >= 2) {
        int n = (int)head[0];
        int m = (int)head[1];
        if (n < 0 || n > MAX_N) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (!(cin >> A[i])) {
                return 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!(cin >> B[i])) {
                return 0;
            }
        }
        cout << solveOne(n, m) << "\n";
        return 0;
    }

    int t = (int)head[0];
    for (int cs = 0; cs < t; ++cs) {
        if (!readAndSolveOne()) {
            return 0;
        }
    }

    return 0;
}