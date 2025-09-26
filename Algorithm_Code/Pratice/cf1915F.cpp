//start:2025-9-14---17:30:00
//  end:2025-9-14---19:03:00
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;
using ordered_set = tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>;


void solve()
{
	int n;
    cin >> n;
    vector<pll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    i64 ans = 0;
    ordered_set ost;
    for(int i = 0; i < n; i++) {
        ost.insert({v[i].second,0});
        ans += i - ost.order_of_key({v[i].second,0});
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