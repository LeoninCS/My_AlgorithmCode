#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

set<int> se = {1,8,49,288,1681,9800,57121,332928};

void solve()
{
	int n = 0;
	cin >> n;
	if(se.count(n)) {
		cout << -1 << endl;
		return;
	} else {
		for(int i = 1; i <= n; i++) {
			if(se.count(i)) {
				cout << i + 1 << " " << i << " ";
				i++;
			} else cout << i << " ";
		}
		cout << endl;
	}
}

void cal()
{
	i64 sum = 0; 
	for(i64 i = 1; i <= 500000; i++) {
		sum += i;
		for(i64 j = 1; j <= i; j++) {
			if(j * j == sum) cout << i << ",";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	//cal();
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}