#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;
//N表示点的数量，M表示边的数量，只有h存点，其他都是边的关系
const int N = 2e5+5, M = 5e5+5;
int n, m;
//稀图用邻链表存图，v表示边权
int h[N], e[M], ne[M], idx, v[M];
//dis表示各点到起始点的距离
//st表示是否确定最短路，删除边权更大的重边
//（边权更大的重边会在堆内，取到时该点已标记为true）
int dis[N];
bool st[M];
//小根堆存储各有距离的点
priority_queue<PII> p;

void add(int a, int b, int c) {
	v[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
	return;
}
int dijkstra() {
	//1为起点，确定有距离为0，还未拓展
	dis[1] = 0;
	p.push({0, 1});
	
	//当p堆不空，即还有点未拓展时
	while (!p.empty()) {
		//取出堆顶，及其对应的点和最短路距离
		auto [dot, d] = p.top();
		p.pop();
		
		//若该点还没有确定最短路
		if (!st[dot]) {
			//确定该点有最短路，删除边权更大的重边的影响
			//（该点此时的距离必为最短路距离）
			st[dot] = true;
			//遍历更新该点的所有邻边，
			//并将小于之前距离的点全部入堆（可能会有重边）
			for (int i = h[dot]; i != -1; i = ne[i]) {
				int j = e[i];
				//若新距离小于之前的，就更新，并入堆
				//传入负距离形成小根堆，也可以直接定义小根堆
				if (dis[j] > -d + v[i]) {
					dis[j] = -d + v[i];
					p.push({-dis[j], j});
				}
			}
		}
	}
	if (dis[n] == 0x7f7f7f7f) return -1;
	else return dis[n];
}
int main()
{
	cin >> n >> m;
	//初始化各点到起始点的距离，距离为N，大于0x3f3f3f3f
	memset(dis, 0x7f, sizeof(dis));	
	memset(h, -1, sizeof(h));
	
	while (m --) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	cout << dijkstra();
	
	return 0;
}