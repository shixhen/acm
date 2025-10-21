#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if 0
    // 简单说明：
    // 输入 p[0..N-1]
    // 1) 计算 c1 = p1-1, c2 = p2-1 - (p1 < p2 ? 1 : 0)
    // 2) v = c1*(N-1) + c2, t = N*(N-1)/2, v' = (v + t) % (N*(N-1))
    // 3) c1' = v'/(N-1), c2' = v'%(N-1)
    // 4) q1 = c1' + 1
    //    q2 = if c2' < q1-1 => c2'+1 else c2'+2
    // 5) 对于 p3..pN：计算其在 p3..pN 中的秩 rank(val) via freq + prefix
    //    S = numbers 1..N excluding q1,q2 (sorted)
    //    q_i = S[ rank(p_i) ]
#endif

    int N;
    if (!(cin >> N)) return 0;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i];

    if (N == 2) {
        // 特判 N=2，交换前后相对（只有两个排列），直接输出 the opposite
        // permutations: [1,2] <-> [2,1]. For any p, q is the other.
        if (p[0] == 1 && p[1] == 2) cout << 2 << ' ' << 1 << '\n';
        else cout << 1 << ' ' << 2 << '\n';
        return 0;
    }

    // 1) 计算 c1, c2 (Lehmer 前两位)
    // c1 = number in {1..N} less than p1 = p1 - 1
    ll c1 = (ll)p[0] - 1;
    // c2 = number in {1..N} \ {p1} that are < p2
    // = p2 - 1 - (p1 < p2 ? 1 : 0)
    ll c2 = (ll)p[1] - 1 - (p[0] < p[1] ? 1 : 0);

    // 2) 合并，加上 t，然后拆分（模 N*(N-1)）
    ll base = (ll)N * (N - 1); // N*(N-1)
    ll v = c1 * (N - 1) + c2; // 范围 [0, N*(N-1)-1]
    ll t = (ll)N * (N - 1) / 2; // N*(N-1)/2
    ll vp = (v + t) % base;
    ll c1p = vp / (N - 1);
    ll c2p = vp % (N - 1);

    // 3) 从初始集合 1..N 选择 q1, q2 (O(1))
    int q1 = (int)(c1p + 1); // 第 c1p (0-based) 个 -> value = c1p+1
    int q2;
    int q1_minus = q1 - 1;
    if (c2p < q1_minus) q2 = (int)(c2p + 1);
    else q2 = (int)(c2p + 2);

    // 4) 处理剩余 p[2..N-1]
    // freq[val] = 1 if val appears in p[2..]
    vector<unsigned char> in_rem(N + 1, 0); // 用小字节节省内存
    for (int i = 2; i < N; ++i) in_rem[p[i]] = 1;

    // prefix counts: prefix[i] = count of values <= i in rem
    vector<int> prefix(N + 1, 0);
    for (int vval = 1; vval <= N; ++vval) {
        prefix[vval] = prefix[vval - 1] + (in_rem[vval] ? 1 : 0);
    }

    // S : sorted list of numbers in {1..N} \\ {q1,q2}
    vector<int> S;
    S.reserve(N - 2);
    for (int vval = 1; vval <= N; ++vval) {
        if (vval == q1 || vval == q2) continue;
        S.push_back(vval);
    }

    // 构造输出 q
    vector<int> q(N);
    q[0] = q1;
    q[1] = q2;

    // 对每个 p[i] (i>=2)， rank = number of rem elements < p[i] = prefix[p[i]-1]
    for (int i = 2; i < N; ++i) {
        int val = p[i];
        int rank = prefix[val - 1]; // 0-based rank among rem
        // S[rank] 存在且对应 q_i
        q[i] = S[rank];
    }

    // 输出
    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << q[i];
    }
    cout << '\n';
    return 0;
}
