#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<vector<char>> S(n, vector<char>(n));
    vector<vector<char>> T(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> T[i][j];
        }
    }
    int ans1 = 0,ans2 = 0, ans3 = 0,ans4 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(S[i][j] != T[i][j]) ans1++;
            if(S[i][j] != T[j][n - i - 1]) ans2++;
            if(S[i][j] != T[n - i - 1][n - 1 - j]) ans3++;
            if(S[i][j] != T[n - 1 - j][i]) ans4++;
        }
    }
    int ans = min({ans1, ans2 + 1, ans3 + 2, ans4 + 3});
    cout << ans << '\n';
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