#include <bits/stdc++.h>

using namespace std;

deque<char> dq[15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    map<char, int> mp;
    mp['0'] = 10;
    mp['A'] = 1;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    for (int i = 1; i <= 9; i++) {
        mp['0' + i] = i;
    }
    vector<int> cnt(15);
    char a;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> a;
            dq[i].push_back(a);
        }
    }
    char c = dq[13].front();
    dq[13].pop_front();
    while (1) {
        cnt[mp[c]]++;
        //cout << c << endl;
        if (cnt[13] == 4)
            break;
        if (c == 'K') {
            c = dq[mp[c]].front();
            dq[13].pop_front();
        } else {
            dq[mp[c]].push_front(c);
            char temp = dq[mp[c]].back();
            dq[mp[c]].pop_back();
            c = temp;
            
        }
        // for (int i = 1; i <= 13; i++) {
        //     for (auto &x : dq[i]) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    int ans = 0;
    for (int i = 0; i <= 12; i++) {
        ans += cnt[i] == 4;
    }
    cout << ans << "\n";
    return 0;
}