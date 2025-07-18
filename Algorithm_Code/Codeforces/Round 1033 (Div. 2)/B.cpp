#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
 

void solve()
{
	int n,s;
    cin >> n >> s;
    int ans = 0;
    while(n--) {
        int dx,dy,x,y;
        cin >> dx >> dy >> x >> y;
        if(dx + dy == 0 && x + y == s) ans++;
        if(dx + dy != 0 && x == y) ans++;
    }
    cout << ans << "\n";
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