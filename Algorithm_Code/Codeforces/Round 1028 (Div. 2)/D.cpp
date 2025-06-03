
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n ; i++ )  {
        cin >> a[i];
        b[i] = a[i];
    }
    vector<tuple<int, int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--,z--;
        queries[i] = {x, y, z};
    } 
    for(int i = q - 1; i >= 0; i--) {
        auto [x, y, z] = queries[i];
        b[x] = max(b[x], b[z]);
        b[y] = max(b[y], b[z]);
        if(z != x && z != y) b[z] = 0;
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = b[i];
    }
    for(int i = 0; i < q; i++) {
        auto [x, y, z] = queries[i];
        b[z] = min(b[x], b[y]);
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(b[i] != a[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
     for(int i = 0; i < n; i++) cout << ans[i] << " ";   
        cout << "\n";
    } else {
        cout << -1 << "\n";
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