#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0; 
	cin >> n;
	map<string,string> mp;
	for(int i = 0; i < n; i++) {
		string s1,s2;
		getline(cin,s1);
		cout << s1 << "--------" << endl;
		getline(cin,s2);
        cout << s2 << "--------" << endl;
		mp[s1] = s2;
	}
	string t;
	getline(cin,t);
	cout << t << "--------" << endl;
	//cout << t;
	//if(mp.count(t)) cout << mp[t];
	//else cout << "The server is busy, please try again later.";
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
} 
