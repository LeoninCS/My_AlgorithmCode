#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n , x;
	cin >> n >> x;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(i != x){
			cout << i << " ";
			cnt++;
		} 
	}
	if(cnt != n) cout << x;
	cout << endl;
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