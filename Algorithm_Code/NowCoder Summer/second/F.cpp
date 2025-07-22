#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') v.push_back(i);
	}
	priority_queue<int> pq;
	int k = v.size();
	pq.push(v[0] + n - 1 - v[k - 1]);
	for(int i = 1; i < k; i++) {
		pq.push(v[i] - v[i - 1] - 1);
	}
	int ans = 0;
	for(int i = 0; i < t / 2 && !pq.empty(); i++) {
		int tp = pq.top();
		pq.pop();
		ans += max((tp - i * 4 - 3), 0);
	}
	int sub = (t - 1) * 2;
	if(t % 2 == 1 && !pq.empty()) {
		int tp = pq.top();
		pq.pop();
		ans += max((tp - sub - 2), 0);
	}
	sub += 2;
	while(!pq.empty()) {
		int tp = pq.top();
		pq.pop();
		ans += max((tp - sub), 0);
	}
	cout << ans;
	cout << "\n";
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