#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	string s = "nowcoder";
	string ss;
	cin >> ss;
	sort(s.begin(),s.end());
	sort(ss.begin(),ss.end());
	if(s == ss) cout << "happy new year";
	else cout << "I AK IOI";
	
}


int main()
{
	int  T = 1;
	//cin >> T;
	
	while(T--) solve();
	
	return 0;
}