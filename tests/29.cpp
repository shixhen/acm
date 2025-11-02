#include <bits/stdc++.h>

using namespace std;

int sum;
int cnt;
void work() {
    int n;
    cin >> n;
    cout << n << endl;
    cout.flush();
    vector<int> a(n + 2);
    vector<int> b(n + 2);
    vector<int> c(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
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
    char op;
    int h, p;
    auto check = [&] (int x) -> bool {
        if (c[x - 1] - c[p - 1] > 0) return false;
        return (b[x - 1] - b[p - 1]) < h;
    };
    while (1) {
        cin >> op;
        if (op == '!') {
            break;
        }
        if (op == '?' && q <= 0) {
            cout << "Too many queries, it should be at most " << n << " [testcase " << cnt << "]" << endl;
        }
        q--;
        sum++;
        vector<int> temp;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x) {
            temp.push_back(x);
        }
        h = temp[0];
        p = temp[1];
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
    }
    vector<int> ans;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        ans.push_back(x);
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        if (ans[i] != a[i + 1]) {
            cout << 111 << endl;
        }
    }
}

int main(int argc, char* argv[]) {

    int t;
    cin >> t;
    while (t--) {
        cnt++;
        work();
    }

}