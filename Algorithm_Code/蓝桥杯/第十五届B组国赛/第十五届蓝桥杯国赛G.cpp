#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

bitset<50000> s[50000];

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for(int i = 1; i <= n; i++) cin >> v[i];
  int ans = 0;
  for(int i = n; i >= 1; i--) {
  	s[i][v[i]] = 1;
	if(i + v[i] <= n) s[i] |= s[i + v[i]];
	if(2 * i <= n) s[i] |= s[2 * i];
	int cnt = s[i].count();
	ans = max(ans,cnt);
  }
  cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}