#include<bits/stdc++.h>
using namespace std;

int dis(int a, int b) 
{
	return abs(a - b);
}

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> pa(n + 1,vector<int>(2,1));
	for(int i = 1; i <= n; i++)  cin >> pa[i][0] >> pa[i][1];
	pa[n][1] = n;
	vector<vector<int>> f(n + 1,vector<int>(2,0));
	for(int i = 1; i <= n; i++) {
		f[i][0] = min(f[i - 1][0] + dis(pa[i - 1][0], pa[i][1]) + dis(pa[i][0], pa[i][1]),
					  f[i - 1][1] + dis(pa[i - 1][1], pa[i][1]) + dis(pa[i][0], pa[i][1])) + 1;
		f[i][1] = min(f[i - 1][1] + dis(pa[i - 1][1], pa[i][0]) + dis(pa[i][0], pa[i][1]),
					  f[i - 1][0] + dis(pa[i - 1][0], pa[i][0]) + dis(pa[i][0], pa[i][1])) + 1;
	}
	cout << f[n][1] - 1;
	return 0;
}
