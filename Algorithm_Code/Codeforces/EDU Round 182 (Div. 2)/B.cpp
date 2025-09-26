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
    int cnt = 0, idx = 0;
    vector<int> vis(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
        if(a[i] == 0) {
            cnt++;
            idx = i;
        } 
    }
    if(cnt == 1) {
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) a[idx] = i;
        }
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(a[i] != i + 1) v.push_back(i);
    }
    int nn = v.size();
    if(nn == 0) {
        cout << 0 << "\n";
    } else {
        int ans = v[nn - 1] - v[0] + 1;
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