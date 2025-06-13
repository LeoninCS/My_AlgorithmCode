#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n; 
    int ans = 2 * n;
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        cout << i << " " << 1 << " " << i << '\n';
        cout << i << " " << min(i + 1, n) << " " << n << '\n';
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