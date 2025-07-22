/*
  
 */

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    map<pair<i64, i64>,i64> mp;
    vector<vector<i64>> v;
    for(int i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        v.push_back({a,b,i});
        mp[{a,b}] = i;
    }
    sort(v.begin(),v.end(),[&](vector<i64> p, vector<i64> pp)->bool {
        return p[0] < pp[0];
    });
    sort(v.begin(), v.begin() + n / 2, [&](vector<i64> p, vector<i64> pp)->bool {
        return p[1] < pp[1];
    });
    sort(v.begin() + n / 2, v.end(), [&](vector<i64> p, vector<i64> pp)->bool {
        return p[1] < pp[1];
    });
    int l = 0, r = v.size() - 1;
    i64 ans = 0;
    while(l < r) { 
        int x = v[l][2];
        int y = v[r][2];
        ans += (abs(v[r][0] - v[l][0]) + abs(v[r][1] - v[l][1]));
        cout << x + 1<< " " << y + 1 << "\n";   
        r--;
        l++;
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