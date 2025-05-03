#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n = 0; 
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 2; i++) {
		if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
} 
