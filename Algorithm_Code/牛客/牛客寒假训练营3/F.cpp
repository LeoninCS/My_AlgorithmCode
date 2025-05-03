#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	int sum = a + b + c - n;
	if(sum < 0 || sum > n) cout << "No" << endl;
	else cout << "Yes" << endl;
	
}


int main()
{
	int  T = 1;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}