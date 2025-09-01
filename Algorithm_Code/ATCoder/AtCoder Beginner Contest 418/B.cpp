#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
    cin >> s;
    long double ans = 0.0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 't') continue;
        long double y = 1;
        for(int j = i + 1; j < s.size(); j++) {
            if(s[j] != 't') continue;
            y++;
            long double res = 0.0;
            if(y > 2) res = (long double)(y - 2)  / (long double)(j - i - 1);
            ans = max(ans, res);
        }
    }
    cout << fixed << setprecision(17) << ans << "\n";
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