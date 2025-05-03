#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int l = 0,r = 1;
	while(r < n) {
		if(s[l] == 'W' && s[r] == 'A') {
			s[l] = 'A';
			s[r] = 'C';
			l--;
			r--;
		} else {
			l++;
			r++;
		}
	}
	cout << s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}