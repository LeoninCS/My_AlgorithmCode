#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s1;
  string s2;
  cin >> s1 >> s2;
  int n = s1.size();
  if(s1[0] != s2[0]) {
    cout << -1 << endl;
    return;
  }
  int cnt = 0;
  for(int i = 1; i < n; i++) {
    if(s1[i] == s2[i]) continue;
    if(s2[i - 1] == s2[i + 1] && s2[i - 1] == s1[i]) cnt++;
    else {
      cout << -1 << endl;
      return;
    }
  }
  cout << cnt << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
  	int t = 0;
  	cin >> t;
  	while(t--) solve();
  	return 0;
}