#include <bits/stdc++.h>

using namespace std;

map<char, int> mp;

double calc(double a, double b, char ch) {
    if (ch == '+') {
        return a + b;
    }
    if (ch == '-') {
        return a - b;
    }
    if (ch == '*') {
        return a * b;
    }
    if (ch == '/') {
        return a / b;
    }
    return -1.0;
}

void solve() {
    stack<char> f;
    stack<double> num;
    double a = 0, b = 0;
    char temp;
    char ch;
    char t;
    while (cin >> temp) {
        a = 0;
        if (temp == '(') {
            f.push(temp);
            continue;
        }
        if (temp == ')') {
            while (f.top() != '(') {
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                t = f.top();
                f.pop();
                num.push(calc(b, a, t));
            }
            f.pop();
            continue;
        } else if (temp <= '9' && temp >= '0'){
            int flag = 0;
            double tt = 0.1;
            while (temp <= '9' && temp >= '0' || temp == '.') {
                if (temp == '.') {
                    flag = 1;
                    cin >> temp;
                    continue;
                }
                if (flag) {
                    a += tt * (temp - '0');
                    tt *= 0.1;
                } else {
                    a = a * 10 + temp - '0';
                }
                cin >> temp;
            }
            num.push(a);
            a = 0;
            ch = temp;
        } else ch = temp;
        if (ch == '#') break;
        if (f.empty()) {
            f.push(ch);
        } else if (temp == ')') {
            while (f.top() != '(') {
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                t = f.top();
                f.pop();
                num.push(calc(b, a, t));
            }
            f.pop();
        } else {
            while (mp[f.top()] >= mp[ch]) {
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                t = f.top();
                f.pop();
                num.push(calc(b, a, t));
                if (f.empty()) break;
            }
            f.push(ch);
        }
    }
    while (num.size() >= 2) {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        ch = f.top();
        f.pop();
        num.push(calc(b, a, ch));
    }
    printf("%.4f\n", num.top());
    return;
}

int main() {
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['('] = 0;
    mp[')'] = 0;
    int t;
    cin >> t;
    while (t--) solve();
    
    
    return 0;
}