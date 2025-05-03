#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int N = 0;
	cin >> N;
	vector<vector<int>> ans(N + 1, vector<int>(N + 1));
	for(int i = 1; i <= N; i++) {
		int j = N + 1 - i;
		if(i <= j && i % 2 == 1) {
			for(int k = i; k <= j; k++) {
				for(int z = i; z <= j; z++) {
					ans[k][z] = 1;
				}
			}
		} else if(i <= j && i % 2 == 0) {
			for(int k = i; k <= j; k++) {
				for(int z = i; z <= j; z++) {
					ans[k][z] = 2;
				}
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(ans[i][j] == 1) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}