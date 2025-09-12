//start:2025-9-12---15:46:00
//  end:2025-9-12---16:04:00
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<PII> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    map<i64,i64> mp[4]; 
    for(int i = 0; i < n; i++) {
        mp[0][v[i].first]++;
        mp[1][v[i].second]++;
        mp[2][v[i].first + v[i].second]++;
        mp[3][v[i].first - v[i].second]++;
    }
    i64 ans = 0;
    for(int i = 0; i < 4; i++) {
        for(auto& [_,k] : mp[i]) {
            ans += (k * (k - 1));
        }
    }
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