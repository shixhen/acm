#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif
#include <bits/stdc++.h>

using namespace std;

int sum;
int cnt;

int get_answer(int n, int m, int l, vector<int> a) {
    reverse(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int, vector<int>, greater<int>> q2;
    int t = min(m, n + 1);
    while (t--) {
        q.push(0);
    }
    for (int i = 1; i <= l; i++) {
        int x = q.top();
        q.pop();
        q.push(x + 1);
        if (!a.empty() && a.back() == i) {
            while (q.size() > 1) {
                q2.push(q.top());
                q.pop();
            }
            while (!q.empty()) {
                q.pop();
            }
            swap(q, q2);
            a.pop_back();
            while (q.size() < a.size() + 1 && q.size() < m) {
                q.push(0);
            }
        }
    }
    while (q.size() > 1) {
        q.pop();
    }
    return q.top();
}
void work() {
    int n = inf.readInt();
    //cerr << "Testcase " << cnt << ": n = " << n << endl;
    int m = inf.readInt();
    int l = inf.readInt();
    cout << n << " " << m << " " << l << endl;
    cout.flush();
    vector<int> a;
    int x = inf.readInt();
    cout << x;
    a.push_back(x);
    for (int i = 1; i < n; i++) {
        x = inf.readInt();
        cout << " " << x;
        a.push_back(x);
    }
    cout << endl;
    cout.flush();
    int answer = get_answer(n, m, l, a);
    reverse(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
    int t = min(m, n + 1);
    for (int i = 1; i <= t; i++) {
        q.push({0, i});
    }
    for (int i = 1; i <= l; i++) {
        auto [x, idx] = q.top();
        q.pop();
        q.push({x + 1, idx});
        cout << idx << endl;
        cout.flush();
        if (!a.empty() && a.back() == i) {
            int y = ouf.readInt(1, m, "idx");
            while (!q.empty()) {
                if (q.top().second != y) {
                    q2.push(q.top());
                }
                q.pop();
            }
            swap(q, q2);
            a.pop_back();
            if (q.size() < a.size() + 1 && q.size() < m) {
                q.push({0, y});
            }
            while (q.size() > a.size() + 1) {
                q.pop();
            }
        }
    }
    while (q.size() > 1) {
        q.pop();
    }
    if (answer != q.top().first) {
        quitf(_wa, "Expected answer %d, but got %d [testcase %d]", answer, q.top().first, cnt);
    }
}

int main(int argc, char* argv[]) {
    //signal(SIGPIPE, SIG_IGN);
    setName("Interactor-freddy");
    registerInteraction(argc, argv);
    int t = inf.readInt();
    cout << t << endl;
    //cerr << "Total testcases: " << t << endl;
    while (t--) {
        cnt++;
        work();
    }
    tout << sum << endl;
}