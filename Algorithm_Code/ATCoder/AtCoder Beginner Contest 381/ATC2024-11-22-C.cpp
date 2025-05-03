#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int count(int idx)
{
	int res = 1;
	int l = idx - 1, r = idx + 1;
	while(l>=0 && r < n && s[l] == '1' && s[r] == '2') {
		res += 2;
		l--;
		r++;
	}
	return res;
}

void solve()
{
	cin >> n;
	cin >> s;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		if(s[i] == '/') v.push_back(i);
	}
	int ans = 0;
	for(int idx: v) ans = max(ans,count(idx)); 
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
} 
