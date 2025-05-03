#include<bits/stdc++.h>
using namespace std;

int cf[100],p[100];
int f[1000005][55];

void solve()
{
	int n, k;
	cin >> n >> k;
	k -= n * (n + 1) * (2 * n + 1) / 6;
	if(k < 0) {
		cout << -1;
		return;
	}	
	for(int i = 1; i <= n; i++) p[i] = (i + n) * (n - i + 1) / 2;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = p[i]; j <= k; j++) {
			if(f[j - p[i]][0]) {
				memcpy(f[j], f[j - p[i]], sizeof(f[j - p[i]]));
				f[j][i]++;
			}
		}
	}	
	if(f[k][0] == 0) cout << -1;
	else {
		for(int i = 1; i <= n; i++) cf[i] += f[k][i];
		for(int i = 1; i <= n; i++) cf[i] += cf[i - 1];
		for(int i = 1; i <= n; i++) cout << cf[i] + i << " ";
	}
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