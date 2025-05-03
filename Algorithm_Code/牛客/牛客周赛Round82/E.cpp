#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n , m;
	cin >> n >> m;
	vector<i64> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<i64> pre(n + 1, 0),aft(n + 2, 0);
	priority_queue<i64> pq;
	for(int i = 0; i < m; i++){
		pq.push(a[i]);
		pre[i + 1] = pre[i] + a[i];
	} 
	for(int i = m; i < n - m; i++) {
		i64 mx = pq.top();
		if(a[i] < mx) {
			pq.pop();
			pq.push(a[i]);
			pre[i + 1] = (pre[i] - mx + a[i]);	
		} else pre[i + 1] = pre[i];
	}
	while(!pq.empty()) pq.pop();
	for(int i = n - 1; i > n - 1 - m; i--) {
		pq.push(b[i]);
		aft[i + 1] = aft[i + 2] + b[i];
	}
	for(int i = n - 1 - m; i >= m; i--) {
		i64 mx = pq.top();
		if(b[i] < mx) {
			pq.pop();
			pq.push(b[i]);
			aft[i + 1] = (aft[i + 2] - mx + b[i]);	
		} else aft[i + 1] = aft[i + 2];
	}
	i64 ans = 1e18;
	//for(int i = m; i <= n - m; i++) cout << pre[i] << " ";
	//cout << endl;
	//for(int i = m; i <= n - m; i++) cout << aft[i + 1] << " ";
	for(int i = m; i <= n - m; i++) {
		ans = min(ans, pre[i] + aft[i + 1]);
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