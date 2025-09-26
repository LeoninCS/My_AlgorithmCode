#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++) {
        map<int,int> mp2;
        int l;
        cin >> l;
        s[i].resize(l);
        for(int j = 0; j < l; j++) {
            cin >> s[i][j];
            if(mp2.count(s[i][j])) continue;
            mp2[s[i][j]]++;
            mp[s[i][j]].push_back(i);
        }
    }
    bool ok = true;
    set<int> se;
    for(int i = 1; i <= m; i++) {
        if(mp[i].size() == 0) {
            ok = false;
            break;
        }
        if(mp[i].size() == 1) {
            se.insert(mp[i][0]);
        }
    }
    if(se.size() > n - 2) ok = false;
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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