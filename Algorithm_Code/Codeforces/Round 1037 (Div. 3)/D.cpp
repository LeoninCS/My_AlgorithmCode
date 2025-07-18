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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(),v.end(),[&](vector<int> x, vector<int> y) -> bool {
        return x[2] < y[2];
    });
    for(int i = 0; i < n; i++) {
        if(k >= v[i][0] && k <= v[i][1]) k = max(k, v[i][2]);
    }
    cout << k << "\n";
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