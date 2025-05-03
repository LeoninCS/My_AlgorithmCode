#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n = 0; 
	cin >> n;
	stack<int> sta;
	for(int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		if(a == 2) {
			if(sta.empty()) cout << 0 << endl;
			else {
				int c = sta.top();
				sta.pop();
				cout << c << endl;
			}
		}
		else {
			int b = 0;
			cin >> b;
			sta.push(b);
		}
	}
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
