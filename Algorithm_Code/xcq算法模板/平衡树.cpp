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
	ordered_set ost;
	//ost.find_by_order(k); 返回下标为k的对象的指针
	//ost.order_of_key(val); 返回小于等于val的数的个数， val可以不存在
	//ost.lower_bound();
	//ost.upper_bound();
	//ost.insert(val);
	//ost.erase(val);
	//ost.erase(ost.lower_bound(val))
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