//https://www.luogu.com.cn/problem/P4779
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define ll long long

ll dist[100010],vis[100010];

int main()
{
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	int n,m,s;
	cin >> n >> m >> s;
	vector<vector<pair<ll,ll>>> graph(n+1);
	while(m--) {
		ll st,en,we;
		cin >> st >> en >> we;
		graph[st].push_back({en,we});
	}
	//Dijkstra
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> heap;
	dist[s] = 0;
	heap.push({dist[s],s});
	while(!heap.empty()) {
		auto p = heap.top();
		heap.pop();
		ll dis = p.first, ver = p.second;
		if(vis[ver]) continue;
		vis[ver] = 1;
		for(auto pa:graph[ver]) {
			int v = pa.first,w = pa.second;
			if(dist[ver]+w<dist[v]) {
				dist[v] = dist[ver]+w;
				heap.push({dist[v],v});
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout << dist[i] << " ";
	return 0;
}
