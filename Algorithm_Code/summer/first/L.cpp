#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using i64 = long long;
using pll = pair<i64,int>;
using ordered_set = tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>;
const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    ordered_set ost;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ost.insert({a[i],i});
    }
    for(int i = 0; i < q; i++) {
        int p, v;
        cin >> p >> v;
        p--;
        ost.erase({a[p],p});
        a[p] += v;
        ost.insert({a[p],p});
        pll pl = *ost.find_by_order((n + 1) / 2);
        i64 ans = ost.order_of_key({pl.first, 0});
        cout << ans << "\n";
    }
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