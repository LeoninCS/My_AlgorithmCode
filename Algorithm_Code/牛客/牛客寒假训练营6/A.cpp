#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];	
	} 
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(b[i] == b[i - 1]) continue;
		ans++;
	}
	cout << ans << endl;
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}