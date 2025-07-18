#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
    cin >> s;
    int idx = 0;
    int cnt = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] != '0') {
            cnt++;
            idx = i;
        }
    }
    int ans = n - idx + cnt - 2;
    cout << ans << "\n";
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