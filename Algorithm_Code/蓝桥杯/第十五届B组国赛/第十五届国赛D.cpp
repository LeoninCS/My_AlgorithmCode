#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 f(i64 n) 
{
	i64 res = 0;
	while(n) {
		res *= 2;
		if(n & 1) res += 1; 
		n /= 2;
	}
	return res;
}


void solve()
{
  int n,m;
  cin >> n >> m;
  vector<i64> a(n);
  i64 ans = 0;
  for(int i = 0; i < n; i++) {
  	cin >> a[i];
  	ans += a[i];
  } 
  vector<i64> dif(n);
  for(int i = 0; i < n; i++) {
  	dif[i] = f(a[i]) - a[i];
	  //cout << dif[i] << " "; 
  }
  vector<vector<i64>> f(m + 1,vector<i64>(2,0));
 for(int i = 0; i < n; i++) {
	 for(int j = m; j >= 1; j--) {
		f[j][0] = max(f[j][1],f[j][0]);
		f[j][1] = max(f[j - 1][0],f[j][1]) + dif[i];
	 }
	 //for(int i = 0; i <= m; i++) cout << f[i] << " ";
	 //cout << endl;
 }
 cout << ans + max(f[m][0],f[m][1]);
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