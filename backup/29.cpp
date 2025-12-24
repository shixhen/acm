#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif
#include <bits/stdc++.h>
#include <csignal>



using namespace std;

int sum;
int cnt;
void work() {
    int n = inf.readInt();
    //cerr << "Testcase " << cnt << ": n = " << n << endl;
    cout << n << endl;
    cout.flush();
    vector<int> a(n + 2);
    vector<int> b(n + 2);
    vector<int> c(n + 2);
    for (int i = 1; i <= n; i++) {
        a[i] = inf.readInt();
        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if (a[i] == 1) {
            b[i]++;
        } else if (a[i] == 2) {
            c[i]++;
        }
    }
    a[n + 1] = 2;
    b[n + 1] = b[n];
    c[n + 1] = c[n] + 1;
    int q = n + 1;
    string op;
    int h, p;
    auto check = [&] (int x) -> bool {
        if (c[x - 1] - c[p - 1] > 0) return false;
        return (b[x - 1] - b[p - 1]) < h;
    };
    while (1) {
        if (ouf.seekEof()) {
            quitf(_wa, "Participant exited prematurely (expected '?' or '!') [testcase %d]", cnt);
        }
        op = ouf.readToken();
        //cerr << "Queries left: " << q << ", total queries: " << sum << ", testcase: " << cnt << " " << op << endl;
        if (op == "!") {
            break;
        }

        if (op == "?" && q <= 0) {
            quitf(_wa, "Too many queries, it should be at most %d [testcase %d]", n, cnt);
        }
        if (op != "?") {
            quitf(_wa, "Expected '?' or '!', but got '%s' [testcase %d]", op.c_str(), cnt);
        }
        q--;
        sum++;
        vector<int> temp;
        if (ouf.seekEof()) {
            quitf(_wa, "Participant exited prematurely (expected query numbers) [testcase %d]", cnt);
        }
        string s = ouf.readLine();
        stringstream ss(s);
        int x;
        string suf;
        while (ss >> x) {
            temp.push_back(x);
        }
        if (temp.size() != 2) {
            quitf(_wa, "Expected 2 numbers in the query, but got %d [testcase %d]", (int)temp.size(), cnt);
        }
        ss.clear();
        if (ss >> suf) {
            quitf(_wa, "Extra characters detected after query numbers [testcase %d]", cnt);
        }
        h = temp[0];
        if (h <= 0 || h > 1000000000) {
            quitf(_wa, "h = %d is out of range [1, 1000000000] [testcase %d]", h, cnt);
        }
        p = temp[1];
        if (p < 1 || p > n) {
            quitf(_wa, "p = %d is out of range [1, %d] [testcase %d]", p, n, cnt);
        }
        int l = p, r = n + 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
        cout.flush();
        //cerr << h << " " << p << " " << l << endl;
    }
    vector<int> ans;
    if (ouf.seekEof()) {
        quitf(_wa, "Participant exited prematurely (expected answer permutation) [testcase %d]", cnt);
    }
    string s = ouf.readLine();
    stringstream ss(s);
    int x;
    string suf;
    while (ss >> x) {
        ans.push_back(x);
    }
    if ((int)ans.size() != n) {
        quitf(_wa, "Expected %d numbers in the answer, but got %d [testcase %d]", n, (int)ans.size(), cnt);
    }
    ss.clear();
    if (ss >> suf) {
        quitf(_wa, "Extra characters detected after answer numbers [testcase %d]", cnt);
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        if (ans[i] != a[i + 1]) {
            quitf(_wa, "Expected %d, but got %d [testcase %d]", a[i + 1], ans[i], cnt);
        }
    }
}

int main(int argc, char* argv[]) {
    setName("Interactor-Tushen");
    registerInteraction(argc, argv);
    int t = inf.readInt();
    cout << t << endl;
    //cerr << "Total testcases: " << t << endl;
    while (t--) {
        cnt++;
        work();
    }
}