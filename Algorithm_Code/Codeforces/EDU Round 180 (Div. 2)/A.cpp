#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
 

void solve()
{
	int a, x , y;
    cin >> a >> x >> y;
    if((a < x && a < y) || (a > x && a > y)) cout << "YES\n";
    else cout << "NO\n"; 
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