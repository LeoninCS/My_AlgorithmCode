#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	int a, b;
    cin >> a >> b;
    if(a == b) cout << 0 << "\n";
    else if(a % b == 0 || b % a == 0) cout << 1 << "\n";
    else cout << 2 << "\n";
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