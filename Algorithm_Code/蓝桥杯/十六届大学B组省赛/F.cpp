#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;


void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int idxs, idxe;
	for(int i = 0; i < n; i++) {
		if(s1[i] == '#' || s2[i] == '#') {
			idxs = i;
			break;
		} 
	}
	for(int i = 0; i < n; i++) {
		if(s1[i] == '#' || s2[i] == '#') idxe = i;
	}
	int ans = 0;
	for(int i = idxs + 1; i <= idxe; i++) {
		if(s1[i] == '#' && s2[i] == '#') continue;
		if(s1[i] == '#') {
			if(s1[i - 1] == '#') continue;
			ans++;
			s2[i] = '#';
		}
		else if(s2[i] == '#') {
			if(s2[i - 1] == '#') continue;
			ans++;
			s1[i] = '#';
		}
		else {
			ans++;
			if(s1[i - 1] == '#') s1[i] = '#';
			if(s2[i - 1] == '#') s2[i] = '#';
		}
	}
	cout << ans;
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