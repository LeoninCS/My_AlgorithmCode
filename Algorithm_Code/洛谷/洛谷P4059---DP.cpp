#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int d[4][4];
int a,b;
int f[3005][3005][3];

int match(char ch)
{
	if(ch == 'A') return 0;
	if(ch == 'T') return 1;
	if(ch == 'G') return 2;
	if(ch == 'C') return 3;	
}

void solve()
{
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> d[i][j];
		}
	}
	cin >> a >> b;
	for (int i = max(n, m); i; i--) {
    f[0][i][0] = f[i][0][0] = f[0][i][2] = f[i][0][1] = INT_MIN/2;
    f[0][i][1] = f[i][0][2] = - a - b * (i - 1);
  }
	f[0][0][1] = f[0][0][2] = INT_MIN/2;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = match(s1[i - 1]);
			int y = match(s2[j - 1]); 
			f[i][j][0] = max({f[i - 1][j - 1][0], f[i - 1][ j - 1][1], f[i - 1][j - 1][2]}) + d[x][y];
			f[i][j][1] = max({f[i][j - 1][1] - b, f[i][j - 1][2] - a, f[i][ j - 1][0] - a});
			f[i][j][2] = max({f[i - 1][j][1] - a, f[i - 1][j][2] - b, f[i - 1][j][0] - a});
		}
	}
	cout << max({f[n][m][0],f[n][m][1],f[n][m][2]});
}

int main()
{
	solve();
	return 0;
}
