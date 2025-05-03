#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

 
void solve()
{
	string s;
	cin >> s;
	while(1) {
		bool br = false;
		int n = s.size();
		for(int i = n; i >= 2; i--) {
			for(int j = 0; j <= n - i; j++) {
				int l = j, r = j + i - 1;
				while(l <= r) {
					if(s[l] == s[r]) {
						l++; r--;
					}
					else break;
				}
				if(l > r) {
					br = true;
					if(i % 2 == 0) s = s.substr(0,j + i / 2) + s.substr(j + i);
					else s = s.substr(0,j + i / 2 + 1) + s.substr(j + i);
					break;
				} 
			}
			if(br) break;
		}
		if(!br) break; 
	}
	cout << s;
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
