#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
	vector<int> v(3);
	for(int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	if((v[0] == v[1] && v[1] == v[2]) ||(v[0] == v[1] - 1 && v[0] == v[2] - 2)) cout << "Yes";
	else cout << "No";
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