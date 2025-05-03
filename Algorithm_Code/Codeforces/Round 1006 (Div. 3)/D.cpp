#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
	int n = 0;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> prel(n + 1,vector<int>(n + 1, 0));
	vector<vector<int>> prem(n + 1,vector<int>(n + 1, 0));
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			prel[i][j + 1] = prel[i][j];
			prem[i][j + 1] = prem[i][j];
			if(a[j] < a[i]) prel[i][j + 1]++;
			else if(a[j] > a[i]) prem[i][j+1]++;
		}
	}
	int l = 0, r = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(prel[i][j + 1] - prem[i][j + 1] > prel[l][r + 1] - prem[l][r + 1]) {
				l = i;
				r = j;
			}
		}
	}
	cout << l + 1<< " " << r + 1<< endl;
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