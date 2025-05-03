#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int n,x,y;

int cal(int z)
{
	int rey = y - z;
	int ren = n - z;
	int k = x + z;
	if(ren <= rey) return (k + 1) * ren;
	else {
		if(k >= ren - rey) return (k + 1) * rey + (k + k - ren + rey + 1) * (ren - rey) / 2;
		else return (k + 1) * rey + (k + 1) * k / 2; 
	}
}

void solve()
{
	cin >> n >> x >> y;
	int mx = 0;
	for(int i = 0; i <= y; i++) {
		mx = max(mx,cal(i));
	}
	cout << mx << endl;
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}