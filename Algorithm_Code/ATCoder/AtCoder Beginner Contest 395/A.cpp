#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		if(a[i] <= a[i - 1]) {
			//cout << a[i] << " " << a[i - 1] << endl;
			cout <<"No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}