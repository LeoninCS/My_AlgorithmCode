#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n , m;
	cin >> n >> m;
	int add = 0;
	if(m % n != 0) add = 1;  
	cout << "Average = " <<(m / n) + add;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
} 
