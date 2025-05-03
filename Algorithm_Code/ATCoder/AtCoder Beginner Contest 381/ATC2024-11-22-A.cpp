#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin >> s;
	if(n % 2 == 0) {
		cout << "No";
		return;
	}
	for(int i = 0; i < (n + 1) / 2 - 1; i++) {
		if(s[i] != '1') {
			cout << "No";
			return;
		}
	}
	if(s[(n + 1) / 2 - 1] != '/') {
		cout << "No";
			return;
	}
	for(int i = (n + 1) / 2; i < n; i++) {
		if(s[i] != '2') {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
} 
