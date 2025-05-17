#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    i64 n,k;
    cin >> n >> k;
    i64 mx = 1;
    for(int i = 0; i < k; i++) mx *= 10;
    i64 ans = 1;
    for(int i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        if(mx % ans == 0 && mx / ans <= a) ans = 1;
        else if(mx % ans != 0 && mx / ans < a) ans = 1;
        else ans *= a;
        //cout << ans << " ";
    }    
    cout << ans << endl;
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