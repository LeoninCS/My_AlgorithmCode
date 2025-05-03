#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
   int n , m;
   cin >> n >> m;
   vector<string> v(n);
   for(int i = 0; i < n; i++) cin >> v[i];
   int x1,y1,x2,y2;
   for(int i = 0; i < n; i++) {
   	for(int j = 0; j < m; j++) {
   			if(v[i][j] == '.') continue;
			if(v[i][j] == '#') {
   				y1 = i; x1 = j;
			}
			if(i > 0 && v[i - 1][j] == '.') continue;
			if(i < n  - 1 && v[i + 1][j] == '.') continue;
			if(j > 0 && v[i][j - 1] == '.') continue;
			if(j < m - 1 && v[i][j + 1] == '.') continue;
			y2 = i; x2 = j;  
	   }
   }
   int ansx = x1 - x2, ansy = y2 - y1;
   cout << ansx << " " << ansy;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}