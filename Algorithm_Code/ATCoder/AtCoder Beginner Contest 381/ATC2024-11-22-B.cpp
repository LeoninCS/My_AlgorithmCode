#include<bits/stdc++.h>
using namespace std;
int rec[26];
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	if(n % 2 != 0) {
		cout << "No";
		return;
	}
	for(int i = 1; i <= n/2; i++) {
		if(s[2 * i - 2] != s[2 * i - 1] || rec[s[2 * i - 2] - 'a']) {
			cout << "No";
			return;
		}
		rec[s[2 * i - 2] - 'a'] = 1;
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
