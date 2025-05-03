#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n = 0;
	cin >> n;
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') cnt0++;
		else cnt1++;
	}	
	cout << (n - 1) * cnt1 + cnt0 << endl;
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