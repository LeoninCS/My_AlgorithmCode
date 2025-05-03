#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
	char ch;
	cin >> ch;
	if(ch == 'U') cout << 'R';
	if(ch == 'D') cout << 'R';
	if(ch == 'L') cout << 'U';
	if(ch == 'R') cout << 'U';
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