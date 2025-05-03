#include<bits/stdc++.h>

using namespace std;
using i64 = long long;


i64 lb(i64 val) 
{
	i64 l = 0,r = 1000000000;
	while(l <= r) {
		i64 mid = l + (r - l) / 2;
		if(val < (mid * (mid - 1) / 2 + 1)) r = mid - 1;
		else l = mid + 1; 
	}
	return r;
}

void solve()
{
	i64 n, l, r;
	cin >> n >> l >> r;
	i64 l_c = lb(l);
	i64 r_c = lb(r);
	if((l_c == r_c - 1 && (l - l_c * (l_c - 1) / 2) > (r - r_c * (r_c - 1) / 2)) || l_c == r_c) cout <<"Yes" << endl;
	else cout <<"No" << endl;	
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