#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{
	int n;
	cin >> n;
	vector<int> v(200000,0);
	vector<i64> len(n);
	for(int i = 0; i < n; i++) {
		i64 a = 0;
		cin >> a;
		v[a]++;
		if(v[a] % 2 == 0) len.push_back(a);
	}
	i64 ans = 0;
	int k = len.size();
	sort(len.begin(),len.end(),[&](const i64 &a,const i64 &b) -> bool {
	return a > b;});
	for(int i = 1; i < k; i += 2) {
		ans += len[i - 1] * len[i];
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