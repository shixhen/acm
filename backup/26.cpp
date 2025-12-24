#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
};


void myString::GetNext(string p, int next[]) {
    next[0] = -1;
    int k = -1;
    int j = 0;
    int n = p.length();
    while (j < n - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int myString::KMPFind(string p, int pos, int next[]) {
    int i = pos;
    int j = 0;
    int n = mainstr.length();
    int m = p.length();
    while (i < n && j < m) {
        if (j == -1 || mainstr[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j >= m) return i - m + 1;
    else return 0;
}

myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    // for(i = 0; i < L; i ++)
    //     cout << next[i] << ' ';
    // cout << endl;
    if (next[L - 1] == 0 && p[0] != p[L - 1]) {
        delete []next;
        return L;
    }
    int v = p.size();
    int j = p.size() - 1;
    while (j) {
        if (next[j] == 0) break;
        v = min(v, j - next[j]);
        j = next[j];
    }
    delete []next;
    return v;
}


void solve() {
    string t;
    cin >> t;
    vector<int> nxt(t.size());
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
    }
    int a = t.size() - nxt.back();
    if (a == t.size()) {
        cout << t.size() << "\n";
        return;
    }
    cout << (a - t.size() % a) % a << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
