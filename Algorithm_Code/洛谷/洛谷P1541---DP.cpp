#include<bits/stdc++.h>

using namespace std;

int cnt1,cnt2,cnt3,cnt4;
int f[41][41][41][41];
int a[355];
int N,M;
void solve()
{
	cin >> N >> M;
	vector<int> a(N);

	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < M; i++) {
		int x = 0;
		cin >> x;
		if(x == 1) cnt1++;
		if(x == 2) cnt2++;
		if(x == 3) cnt3++;
		if(x == 4) cnt4++;
	} 
	f[0][0][0][0] = a[0];
	for(int i = 0; i <= cnt1; i++) {
		for(int j = 0; j <= cnt2; j++) {
			for(int k = 0; k <= cnt3; k++) {
				for(int l = 0; l <=cnt4; l++) {
					int idx = 1 * i + 2 * j + 3 * k + 4 * l;
					if(i != 0) f[i][j][k][l] = max(f[i][j][k][l],f[i - 1][j][k][l] + a[idx]);
					if(j != 0) f[i][j][k][l] = max(f[i][j][k][l],f[i][j - 1][k][l] + a[idx]);
					if(k != 0) f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k - 1][l] + a[idx]);
					if(l != 0) f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k][l - 1] + a[idx]);
				}
			}
		}
	}
	cout << f[cnt1][cnt2][cnt3][cnt4];
}


int main()
{
	solve();
	return 0;
}
