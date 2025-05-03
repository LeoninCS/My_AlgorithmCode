#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	//lb
	auto lb = [&](int val, int jud) -> int {
	int l = 0, r = n - 1; 
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(a[mid] > val) r = mid - 1;
		else  l = mid + 1;
		
	}
	if( l < n && a[l] == val) return l;
	else {
		if(jud) return l - 1;
		else return l;
	}
	}; 
	//left
	for(int i = 0; i <= m / 2; i++) {
		int ri = i;
		int le = m - ri * 2;
		ans = max(ans,lb(ri,1) - lb(-le,0) + 1);
	}
	//right
	for(int i = 0; i <= m / 2; i++) {
		int le = i;
		int ri = m - le * 2;
		ans = max(ans,lb(ri,1) - lb(-le,0) + 1);
	}
	cout << ans;
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