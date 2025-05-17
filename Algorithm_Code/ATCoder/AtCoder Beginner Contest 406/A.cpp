#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(c < a || (c == a && d <= b)) cout << "Yes" << endl;
    else  cout << "No" << endl; 
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