#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto [x,y] : mp) {
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    int nn = v.size();
    int ans = 0;
    for(int i = 0; i < nn; i++) {
        int cnt = v[i].first * (nn - i);
        ans = max(ans, cnt);
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