#include <bits/stdc++.h>
<<<<<<< HEAD

using namespace std;


int main() {
    string s;
    getline(cin, s);
    cout << s.substr(0, 5) << endl;
    return 0;
=======
using namespace std;
using ll = long long;
const int mod = 998244353;
struct node {
	ll t, v;
}aa[50];
int cmp(const node& a, const node& b) {
	return a.v < b.v;
}
struct node2 {
	ll t, v;
};
int cmp2(const node2& a, const node2& b) {
	return a.t > b.t;
}
struct node3 {
	ll t, v, s;
};
int cmp3(const node3& a, const node3& b) {
	return a.t < b.t;
}
vector<node2> vec[30];
vector<node3> vec2;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>aa[i].t;
	for(int i = 0; i < n; i++) cin>>aa[i].v;
	sort(aa, aa + n, cmp);
	int n2 = n / 2, n3 = n - n2;
	ll val, tt, ss, cnt;
	for(int i = 0; i < 1 << n2; i++) {
		val = 0;
		tt = 0;
		cnt = 0;
		for(int j = 0; j < n2; j++) {
			if((i >> j) & 1) {
				val += aa[j].v * cnt;
				tt += aa[j].t;
				cnt++;
			}
		}
		if(tt > m) continue;
		vec[__builtin_popcount(i)].push_back((node2){tt, val});
	}

	for(int i = 0; i < 1 << n3; i++) {
		val = 0;
		tt = 0;
		cnt = 0;
		ss = 0;
		for(int j = 0; j < n3; j++) {
			if((i >> j) & 1) {
				val += aa[j + n2].v * cnt;
				ss += aa[j + n2].v;
				tt += aa[j + n2].t;
				cnt++;
			}
		}
		if(tt > m) continue;
		vec2.push_back((node3){tt, val, ss});
	}
	sort(vec2.begin(), vec2.end(), cmp3);

	ll ans = 0, tmp;
	for(int l = 0; l <= n2; l++) {
		int i = 0;
		tmp = 0;
		sort(vec[l].begin(), vec[l].end(), cmp2);
		for(auto [T, V]: vec[l]) {
			while(i < vec2.size() && vec2[i].t + T <= m) {
				tmp = max(tmp, l * vec2[i].s + vec2[i].v);
				i++;
			}
			ans = max(ans, V + tmp);
		}
	}
	cout<<ans;
	return 0;
>>>>>>> 72c8a7564b12082d3a339384fb7deab4800507b9
}