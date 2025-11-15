#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    long long l = -k, r = k;
    vector<long long> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    deque<long long> deque;
    for (auto &i: a) deque.push_back(i);
    while (deque.front() < l && deque.size()) {
        deque.pop_front();
    }
    while (deque.back() > r && deque.size()) {
        deque.pop_back();
    }
    long long op, x;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            r -= x;
            l -= x;
            while (deque.back() > r && deque.size()) {
                deque.pop_back();
            }
        } else if (op == 2) {
            cin >> x;
            l += x;
            r += x;
            while (deque.front() < l && deque.size()) {
                deque.pop_front();
            }
        } else {
            cout << deque.size() << '\n';
        }
    }
    return 0;
}