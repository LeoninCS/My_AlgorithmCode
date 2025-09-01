#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<i64,i64>> v;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) swap(a[i], b[i]);
        v.push_back({a[i],b[i]});
    }
    sort(v.begin(),v.end(),[&](pair<i64,i64> a, pair<i64,i64> b)->bool {
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });
    //for(int i = 0; i < n; i++) {
    //    cout << v[i].first << " " << v[i].second << "\n";
    //}
    vector<i64> mi(n + 1, 1e18);
    for(int i = n - 1; i >= 0; i--) {
        mi[i] = min(mi[i + 1], v[i].second);
    }
    i64 add = 1e18;
    for(int i = 0; i < n; i++) {
        add = min(2LL * (mi[i + 1] - v[i].first), add);
    }
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        ans += v[i].first - v[i].second;
    }
    ans += max(0LL, add);
    cout << ans << "\n";
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