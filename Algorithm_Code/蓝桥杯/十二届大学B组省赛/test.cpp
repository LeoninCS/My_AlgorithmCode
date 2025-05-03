#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int gcd(int a,int b) {
	if(a % b == 0) return b; 
	return gcd(b, a % b);
}

void solve()
{
	int n = 2021;
	vector<vector<pair<int,int>>> gra(n + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= i + 21; j++) {
			int g = gcd(i,j);
			int len = i * j / g;
			gra[i].push_back({len,j});
			gra[j].push_back({len,i});
		}
	}
	vector<int> vis(n + 1, 0);
	vector<int> dis(n + 1, inf);
	priority_queue<pair<int,int>,vector<int,int>,greater<>> pq;
	dis[1] = 0;
	pq.push({0,1});
	while(pq.empty()) {
		auto tp = pq.top();
		pq.pop();
		int d = tp.first;
		int e = tp.second;
		for(auto pa: gra[e]) {
			auto dd = pa.first;
			int ee = pa.second; 
			if(!vis[ee] && dis[e] + dd < dis[ee]) {
				dis[ee] = dis[e] + dd;
				vis[ee] = 1;
				pq.push({dis[ee],ee});
			}
		}
	}
	cout << dis[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}