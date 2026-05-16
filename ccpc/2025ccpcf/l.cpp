#include <bits/stdc++.h>

using namespace std;

struct Basis {
    long long b[32] = {0};

    void insert(long long x) {
        for (int i = 31; i >= 0; i--) {
            if (!((x >> i) & 1)) continue;
            if (b[i]) {
                x ^= b[i];
            } else {
                for (int j = 0; j < i; j++) {
                    if ((x >> j) & 1) {
                        x ^= b[j];
                    }
                }
                b[i] = x;
                for (int j = i + 1; j < 32; j++) {
                    if ((b[j] >> i) & 1) {
                        b[j] ^= x;
                    }
                }
                return;
            }
        }
    }
};


unsigned long long get_hash(const Basis& b) {
    unsigned long long h = 0;
    for (int i = 0; i < 32; i++) {
        h = h * 1099511628211ull + b.b[i];
    }
    return h;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_set<unsigned long long> all;
    vector<Basis> cur;
    for (int i = 1; i <= n; i++) {
        vector<Basis> nb;
        unordered_set<unsigned long long> s;
        Basis t;
        t.insert(a[i]);
        if (!s.count(get_hash(t))) {
            s.insert(get_hash(t));
            nb.push_back(t);
        }
        for (auto &x : cur) {
            Basis nt = x;
            nt.insert(a[i]);
            if (!s.count(get_hash(nt))) {
                s.insert(get_hash(nt));
                nb.push_back(nt);
            }
        }
        for (auto &x : nb) {
            all.insert(get_hash(x));
        }
        cur = nb;
    }
    cout << all.size() << "\n";

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