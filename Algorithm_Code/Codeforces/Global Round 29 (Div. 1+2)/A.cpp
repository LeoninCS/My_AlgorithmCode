#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int x, y;
    cin >> x >> y;
    if(x < y) cout << 2 << "\n";
    else if(x == y) cout << -1 << "\n";
    else {
        if(x - 1 > y && y > 1) cout << 3 << "\n";
        else cout << -1 << "\n";
    }
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