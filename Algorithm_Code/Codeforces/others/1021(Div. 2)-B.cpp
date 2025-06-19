#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int ans = 0;
  if(n % 2 == 0) {
    int l = n / 2 - 1;
    int r = n / 2;
    k /= 2;
    l -= k;
    r += k;
    ans = a[r] - a[l] + 1;
  } else {
    int l = n / 2;
    int r = n / 2;
    k = (k + 1) / 2;
    l -= k;
    r += k;
    ans = a[r] - a[l] + 1;
  }
  cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}