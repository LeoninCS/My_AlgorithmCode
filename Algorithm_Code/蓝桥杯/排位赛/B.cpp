#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, s, e, d;
	cin >> n >> s >> e >> d;
	int front = (s - d + n) % n;
	int end = (s + d + n) % n;
	int ans1,ans2,ans3;
	if(front <= e) ans1 = e - front;
	else ans1 =  e - front + n;
	if(end <= e) ans2 = e - end;
	else ans2 = e - end + n;
	if(s <= e) ans3 = e - s;
	else ans3 = e - s + n;
	int ans = min({ans1, ans2, ans3});
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