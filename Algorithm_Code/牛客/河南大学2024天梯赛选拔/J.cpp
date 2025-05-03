#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	vector<pair<int,int>> orginal(n + 1);
	map<pair<int,int>,vector<int>> mp;
	orginal[0].first = 0;
	orginal[0].second = 0;
	mp[orginal[0]].push_back(0);
	int x = 0,y = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i - 1] == 'U') y += 1;
		else if(s[i - 1] == 'D') y -= 1;
		else if(s[i - 1] == 'L') x -= 1;
		else if(s[i - 1] == 'R') x += 1;
		orginal[i].first = x;
		orginal[i].second = y;
		mp[orginal[i]].push_back(i);
	}
	auto lb = [&](int v,pair<int,int> pa) ->int {
		int lbl = 0, lbr = mp[pa].size() - 1;
		while( lbl <= lbr) {
			int mid = lbl + (lbr - lbl) / 2;
			if(mp[pa][mid] > v) lbr = mid - 1;
			else lbl = mid + 1; 
		}
		return lbl;
	};
	while(m--) {
		int l, r;
		cin >> l >> r;
		int ans = lb(r, orginal[l - 1]) - lb(l, orginal[l - 1]);
		cout << ans << endl;
		//cout << lb(r,orginal[l - 1]) << "-" << lb(l, orginal[l - 1]) << endl;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}