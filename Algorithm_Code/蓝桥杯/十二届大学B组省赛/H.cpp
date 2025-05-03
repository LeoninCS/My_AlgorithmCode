#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int c(int up,int down) 
{
	int res = 1;
	for(int i = 0; i < up; i++) {
		res *= down;
		down--;
	}
	for(int i = 1; i <= up; i++) {
		res /= i;
	}
	return res;
}

void solve()
{
	int n = 0;
	cin >> n;
	for(int i = 1; i <= 1000; i++) {
		for(int j = 0; j < i; j++) {
			if(c(j,i) == n) {
				int ans = 0;
				for(int z = 0; z <= i; z++) {
					ans += z;
				}
				ans += (j + 1);
				cout << ans;
				return;
			}
		}
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