#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(),v.end(),[&](const string &s1,const string &s2)->bool {
	return s1.size() < s2.size();
	});
	for(int i = 0 ; i < n; i++) cout << v[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}