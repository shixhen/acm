#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx) {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // nextSmaller[i] = smallest j>i with a[j] < a[i], else n+1
    vector<int> nextSmaller(n+1, n+1);
    {
        vector<int> st;
        for (int i = n; i >= 1; --i) {
            while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
            nextSmaller[i] = st.empty() ? (n+1) : st.back();
            st.push_back(i);
        }
    }

    // prevGreater[i] = largest j<i with a[j] > a[i], else 0
    vector<int> prevGreater(n+1, 0);
    {
        vector<int> st;
        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
            prevGreater[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }
    }

    // bucket[r] contains indices i such that nextSmaller[i] == r (we will activate when r reached)
    vector<vector<int>> bucket(n+2);
    for (int i = 1; i <= n; ++i) {
        if (nextSmaller[i] <= n) bucket[nextSmaller[i]].push_back(i);
    }

    Fenwick fw(n);
    ll ans_pairs = 0;
    // process r from 1..n
    for (int r = 1; r <= n; ++r) {
        // activate all i whose nextSmaller == r (meaning nextSmaller[i] <= current r)
        for (int i : bucket[r]) fw.add(i, 1);
        // for current r, number of i in [1..prevGreater[r]] with nextSmaller[i] <= r is:
        if (prevGreater[r] > 0) ans_pairs += fw.sum(prevGreater[r]);
    }

    // total distinct arrays = original array (1) + number of distinct non-original results
    cout << (ans_pairs + 1) << "\n";
    return 0;
}
