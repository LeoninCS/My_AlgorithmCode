#include<bits/stdc++.h>
using namespace std;

string tem1 = "01",tem2 = "10";

int add(string s) 
{
	int n = s.size();
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') s[i] = '1';
		else s[i] = '0';
		
		int cnt1 = 0, cnt2 = 0;
		for(int j = 0; j < n - 1; j++) {
			string sub = s.substr(j,2);
			if(sub == tem1) cnt1++;
			if(sub == tem2) cnt2++; 
		}
		if(cnt1 == cnt2) cnt++;
		
		if(s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
	return cnt;
}


void solve()
{
	int n;
	string s;
	cin >> n >> s; 
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '?') cnt++;
	}
	
	int ans = 0;
	
	function<void(int,int)> dfs = [&](int num, int idx) -> void{
		if(num == cnt) ans += add(s);
		
		for(int i = idx; i < n; i++) {
			if(s[i] != '?') continue;
			s[i] = '0';
			dfs(num + 1, i + 1);
			s[i] = '1';
			dfs(num + 1, i + 1);
			s[i] = '?';
		}
	};
	
	dfs(0,0);
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}