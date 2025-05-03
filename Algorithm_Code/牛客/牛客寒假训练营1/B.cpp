#include<bits/stdc++.h>

using namespace std;


int pa[100005];

int find(int x) 
{
	if(pa[x] != x) pa[x] = find(pa[x]);
	return pa[x];
}

void merge(int x,int y)
{
	x = find(x),y=find(y);
	pa[y] = x;
}

void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) pa[i] = i; 
	vector<int> node(n + 1, 0);
	for(int i = 0; i < n - 1; ++i) {
		int u,v;
		cin >> u >> v;
		merge(u, v);
		node[u]++;
		node[v]++;
	}
	
	int cnttree = 0;
	int cntnode = 0;
	int x = 1, y = 2;
	for(int i = 1; i <= n; ++i) {
		if(pa[i] == i) cnttree++;
		if(node[i] == 1) {
			if(node[x] == 1) y = i;
			else x = i;
			cntnode++;
		}		
	}
	if(cnttree > 1 || cntnode > 2) cout << -1 << endl;
	else cout << x << " " << y << endl; 
}


int main()
{
	int T = 1;
	
	while(T--) solve();
	
	return 0;
}
