#include<bits/stdc++.h>
using namespace std;
int n, k;
int ans[55];
bool dfs(int le, int val,int sum)
{
	if(sum == k && le == n) return true;
	else if(sum < k && le < n) {
		for(int i = val + 1; i < n; i++) {
			ans[le] = i;
			if(dfs(le + 1, i, sum + le * i)) return true;
		}	
	}
	return false; 
}


void solve()
{
	cin >> n >> k;
	if(dfs(1,0,0)) {
		for(int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
	}
	else cout << -1 << endl;
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