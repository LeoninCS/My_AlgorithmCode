#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n = 0;
    cin >> n;
    vector<vector<int>> v(100000,vector<int>(0)); 
    vector<int> h(n);
    for(int i = 0; i < n ; i++) cin >> h[i];
    for(int i = 0 ; i < n; i++) {
        for(int j = 1; j * j <= h[i]; j++) {
            if(h[i] % j == 0) {
                v[j].push_back(h[i]);
                if(h[i] / j != j) v[h[i] / j].push_back(h[i]);
            }
        }
    }
    vector<int> ans;
    for(int i = 100000; i >= 1; i--) {
        if(v[i].size() >=3 ) {
           sort(v[i].begin(),v[i].end());
		    cout << v[i][0] << " " << v[i][1] << " " << v[i][2];
			break;
        }
    }
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