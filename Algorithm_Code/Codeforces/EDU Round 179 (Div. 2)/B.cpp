#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n , m;
    cin >> n >> m;
	vector<tuple<int, int, int>> vv;
	for(int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vv.push_back({x, y, z});
	}
    int f1 = 1, f2 = 2;
    for(int i = 3; i <= n; i++) {
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    for(int i = 0; i < m; i++) {
        auto [x, y, z] = vv[i];
        if(x >= f2 && y >= f2 && z >= f2) {
            if(z >= f1 + f2) cout << '1';
            else {
                if(y > x) swap(x, y);
                int re = x - f2;
                if(re >= f1) cout << '1';
                else cout << '0';
            }   
        } else {
            cout << '0';
        }
    }
    cout << '\n';
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