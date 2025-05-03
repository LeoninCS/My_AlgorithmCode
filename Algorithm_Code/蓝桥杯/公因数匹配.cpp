#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  unordered_map<int,int> ump;
  int l = 10000000, r = 100000000;
  for(int i = 0; i < n; i++) {
  	for(int j = 2; j * j <= a[i]; j++) {
  		while(a[i] % j == 0) {
  			if(ump.count(j)) {
				if(ump[j] < l || (ump[j] == l && i <= r) ) {
					l = ump[j];
					r = i;
				}
				a[i] /= j;
				continue;
			  }
  			ump[j] = i;
			 a[i] /= j;		
		  }
	  }
    if(a[i] > 1) {
      if(ump.count(a[i])) {
        if(ump[a[i]] < l || (ump[a[i]] == l && i <= r) ) {
					l = ump[a[i]];
					r = i;
				}
      } else {
        ump[a[i]] = i;
      }
    }
  }
  cout << l + 1 << " " << r + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
  	int t = 1;
  	//cin >> t;
  	while(t--) solve();
  	return 0;
}