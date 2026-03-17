#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 105;
constexpr int MAXM = 10;
constexpr int MAXMASK = 1 << MAXM;

int n, m;
pair<int, int> horse[MAXM];
int horse_id[MAXN][MAXN];

bool attacked[MAXMASK][MAXN][MAXN];
int dp[MAXMASK][MAXN][MAXN];

inline bool in_board(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= n;
}

inline bool alive_horse_at(int x, int y, int captured_mask) {
    if (!in_board(x, y)) {
        return false;
    }
    int id = horse_id[x][y];
    if (id == -1) {
        return false;
    }
    return ((captured_mask >> id) & 1) == 0;
}

void build_attacked_table() {
    const int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    const int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
    const int lx[8] = {1, 1, -1, -1, 0, 0, 0, 0};
    const int ly[8] = {0, 0, 0, 0, 1, 1, -1, -1};

    int all_mask = 1 << m;
    for (int mask = 0; mask < all_mask; ++mask) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                attacked[mask][i][j] = false;
            }
        }

        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                continue;
            }
            int x = horse[i].first;
            int y = horse[i].second;

            for (int k = 0; k < 8; ++k) {
                int leg_x = x + lx[k];
                int leg_y = y + ly[k];
                int to_x = x + dx[k];
                int to_y = y + dy[k];

                if (!in_board(to_x, to_y)) {
                    continue;
                }
                if (!in_board(leg_x, leg_y)) {
                    continue;
                }
                if (alive_horse_at(leg_x, leg_y, mask)) {
                    continue;
                }
                attacked[mask][to_x][to_y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(horse_id, -1, sizeof(horse_id));

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        horse[i] = {x, y};
        horse_id[x][y] = i;
    }

    build_attacked_table();

    if (attacked[0][0][0]) {
        cout << 0 << '\n';
        return 0;
    }

    int all_mask = 1 << m;
    dp[0][0][0] = 1;

    for (int mask = 0; mask < all_mask; ++mask) {
        for (int x = 0; x <= n; ++x) {
            for (int y = 0; y <= n; ++y) {
                int cur = dp[mask][x][y];
                if (cur == 0) {
                    continue;
                }
                if (attacked[mask][x][y]) {
                    continue;
                }

                if (x + 1 <= n) {
                    int nx = x + 1;
                    int ny = y;
                    int nmask = mask;
                    int id = horse_id[nx][ny];
                    if (id != -1 && ((mask >> id) & 1) == 0) {
                        nmask |= (1 << id);
                    }
                    if (!attacked[nmask][nx][ny]) {
                        dp[nmask][nx][ny] += cur;
                        if (dp[nmask][nx][ny] >= MOD) {
                            dp[nmask][nx][ny] -= MOD;
                        }
                    }
                }

                if (y + 1 <= n) {
                    int nx = x;
                    int ny = y + 1;
                    int nmask = mask;
                    int id = horse_id[nx][ny];
                    if (id != -1 && ((mask >> id) & 1) == 0) {
                        nmask |= (1 << id);
                    }
                    if (!attacked[nmask][nx][ny]) {
                        dp[nmask][nx][ny] += cur;
                        if (dp[nmask][nx][ny] >= MOD) {
                            dp[nmask][nx][ny] -= MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < all_mask; ++mask) {
        ans += dp[mask][n][n];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}