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
    int n = 2;
    //cerr << "Testcase " << cnt << ": n = " << n << endl;
    int m = 3;
    int l = 6;
    cout << n << " " << m << " " << l << endl;
    cout.flush();
    vector<int> a;
    int x = 3;
    cout << 2;
    a.push_back(2);
    a.push_back(3);
    for (int i = 1; i < n; i++) {
        cout << " " << x;
        //a.push_back(x);
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
            int y;
            cin >> y;
            while (!q.empty()) {
                if (q.top().second != y) {
                    q2.push(q.top());
                }
                cout << "Popped: " << q.top().second << endl;
                q.pop();
            }
            swap(q, q2);
            a.pop_back();
            cout << a.size() << "   ---- " << q.size() << "   " << endl;
            if (q.size() < a.size() + 1 && q.size() < m) {
                q.push({0, y});
            }
            if (q.size() > a.size() + 1) {
                q.pop();
            }
        }
    }
    while (q.size() > 1) {
        q.pop();
    }
    cout << "Answer: " << q.top().first << endl;

}

int main(int argc, char* argv[]) {
    //signal(SIGPIPE, SIG_IGN);

    int t = 1;
    //cerr << "Total testcases: " << t << endl;
    while (t--) {
        cnt++;
        work();
    }
}