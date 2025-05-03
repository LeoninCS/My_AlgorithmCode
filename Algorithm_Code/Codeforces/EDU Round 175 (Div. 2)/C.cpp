#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	 int n, k; 
	 cin >> n >> k;
	 string s;
	 cin >> s;
	 vector<i64> a(n);
	 for(int i = 0; i < n; i++) cin >> a[i];
	 
	 auto check = [&](int mid) -> bool {
	 	int cnt = 0;
		for(int i = 0; i < n; i++) {
	 		if(a[i] <= mid || s[i] == 'R') continue;
	 		cnt++;
			for(int j = i; j < n; j++) {
	 			i = j;
				if(a[j] <= mid || s[i] == 'B') continue;
				else break;	
			}	
		}
		return cnt <= k;
	 };
	 
	 i64 l = 0, r = inf;
	 while(l <= r) {
		int mid = l + (r - l) / 2;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	 }
	 cout << l << endl;
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