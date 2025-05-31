#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = min(a, c);
    b = min(b, d);
    if(a < b) cout << "Flower\n";
    else cout << "Gellyfish\n";
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