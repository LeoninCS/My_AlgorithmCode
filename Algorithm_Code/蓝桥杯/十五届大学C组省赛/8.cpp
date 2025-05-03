#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
	cin >> s;
	int l = 0; int r = s.size() - 1;
	while(l < r) {
		while(l < r && (s[l] == 'l' || s[l] == 'q' || s[l] == 'b')) l++;
		while(l < r && (s[r] == 'l' || s[r] == 'q' || s[r] == 'b')) r--;
		if(s[l] != s[r]) {
			cout << "No" << endl;
			return;
		}		
		l++;
		r--;	
	}
	cout << "Yes" << endl;
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