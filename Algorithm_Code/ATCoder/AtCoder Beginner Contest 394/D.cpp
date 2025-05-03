#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	stack<char> sta;
	for(int i = 0; i < n; i++) {
		//if(s[i] == '(' || s[i] == '[' || s[i] == '<') sta.push(s[i]);
		if(sta.size() && s[i] == ')' && sta.top() == '(') sta.pop();
		else if(sta.size() && s[i] == ']' && sta.top() == '[') sta.pop();
		else if(sta.size() && s[i] == '>' && sta.top() == '<') sta.pop();
		else sta.push(s[i]);
	}
	if(sta.size()) cout << "No";
	else cout << "Yes";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}