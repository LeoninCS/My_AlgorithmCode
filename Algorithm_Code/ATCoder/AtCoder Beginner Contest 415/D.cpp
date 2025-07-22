#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n, m;
    cin >> n >> m;
    vector<pair<i64,i64>> v;
    for(int i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b;
        v.push_back({a, a - b});
    }
    sort(v.begin(), v.end(),[&](pair<i64, i64> f, pair<i64, i64> s)->bool {
        return f.second < s.second;
    });
    i64 ans = 0;
    i64 l = 0;
    while(l < m) {
        if(n >= v[l].first) {
            i64 d = (n - v[l].first) / v[l].second + 1;
            ans += d;
            n -= d * v[l].second;
        } else {
            l++;
        }
    }
    cout << ans << "\n";
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