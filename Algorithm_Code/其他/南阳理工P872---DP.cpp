#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   int n,a,b,c,d;
   cin >> n >> a >> b >> c >> d;
   string s;
   cin >> s;
   vector<vector<int>> f(n + 1, vector<int>(6,0));
   char ch[6] = {'A','A','B','B',' ',' '};
   char at[6] = {'G','G','A','A','B','B'};
   int x[6] = {b,b,a,a,c,c};
   for(int i = 1; i <= n; i++) {
   	for(int j = 0; j < 6; j++) {
   		if(j % 2 == 0) {
   			for(int k = 0; k < 6; k++) {
   				if(k == j || k == j + 1) continue;
   				f[i][j] = max(f[i][j],f[i - 1][k]);
			   }
			   f[i][j] += d * (int)(ch[j] == s[i - 1]) + x[j] * (int)(at[j] == s[i - 1]);
		   }
		else {
			for(int k = 0; k < 6; k++) {
   				if(k == j) continue;
   				f[i][j] = max(f[i][j],f[i - 1][k]);
			   }
			   f[i][j] += d * (int)(ch[j] == s[i - 1]) + x[j] * (int)(at[j] == s[i - 1]);;
		}
	   }
   }
   int ans = 0;
   for(int i = 0; i < 6; i++) ans = max(ans, f[n][i]);
   cout << ans;    
   return 0;
}
