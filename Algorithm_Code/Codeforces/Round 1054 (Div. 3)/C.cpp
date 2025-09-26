#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int,int> mp;
    mp[k] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(mp.count(i)) continue;
        else ans++;
    }
    ans += max(0, mp[k] - ans);
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