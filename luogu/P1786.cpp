#include <bits/stdc++.h>

using namespace std;

struct people {
    string name;    // 名字
    string pos;     // 职位
    int con;        // 帮贡
    int level;      // 等级
    int idx;        // 输入顺序
};

string get_new_pos(int idx) {
    if (idx <= 2) {
        return "HuFa";
    }
    if (idx <= 6) {
        return "ZhangLao";
    }
    if (idx <= 13) {
        return "TangZhu";
    }
    if (idx <= 38) {
        return "JingYing";
    }
    return "BangZhong";
}

int get_pos_id(string pos) {
    if (pos == "BangZhu") return 1;
    if (pos == "FuBangZhu") return 2;
    if (pos == "HuFa") return 3;
    if (pos == "ZhangLao") return 4;
    if (pos == "TangZhu") return 5;
    if (pos == "JingYing") return 6;
    return 7;
}

bool cmp1(const people &a, const people &b) {
    return (a.con > b.con || (a.con == b.con && a.idx < b.idx));
}

bool cmp2(const people &a, const people &b) {
    if (get_pos_id(a.pos) != get_pos_id(b.pos)) {
        return get_pos_id(a.pos) < get_pos_id(b.pos);
    }
    if (a.level != b.level) {
        return a.level > b.level;
    }
    return a.idx < b.idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<people> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].pos >> v[i].con >> v[i].level;
        v[i].idx = i;
    }
    sort(v.begin() + 2, v.end(), cmp1);
    int j = 1;
    for (int i = 0; i < n; i++) {
        if (v[i].pos == "BangZhu" || v[i].pos == "FuBangZhu") {
            continue;
        }
        v[i].pos = get_new_pos(j++);
    }
    sort(v.begin(), v.end(), cmp2);
    for (auto &x : v) {
        cout << x.name << " " << x.pos << " " << x.level << "\n";
    }
    return 0;
}