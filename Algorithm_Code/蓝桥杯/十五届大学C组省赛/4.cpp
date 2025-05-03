#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int ha[10] = {1,0,0,0,1,0,1,0,2,1};
	int n = 0;
	cin >> n;
	vector<pair<int,int>> ans;
	while(n--) {
		int a = 0;
		cin >> a;
		int tem = a;
		int se = 0;
		while(tem) {
			int mod = tem % 10;
			se += ha[mod];
			tem /= 10;
		}
		ans.push_back({a,se});
	}
	sort(ans.begin(),ans.end(),[&](const pair<int,int> pa,const pair<int,int> pb) -> bool {
		if(pa.second == pb.second) return pa.first < pb.first;
		else return pa.second < pb.second;
	});
	for(auto &pa: ans) cout << pa.first << " ";
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