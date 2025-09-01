#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n;
    cin >> n;
    if(n % 2 == 0) {
        i64 ans =  ((n + 1) + (n / 2)) * 2;
        cout << ans << endl;
    } else {
        i64 ans = ((n) + ((n + 1) / 2)) * 2;
        cout << ans << endl;
    }
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