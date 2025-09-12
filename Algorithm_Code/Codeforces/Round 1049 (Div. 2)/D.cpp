#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
    int n;
    cin >> n;
    vector<PII> a(n);
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].second - a[i].first;
    }
    //cout << ans << "\n";
    sort(a.begin(),a.end(),[&](PII x, PII y)->bool{
         
    });
    vector<i64> pre(n + 1);
    for(int i = 1; i < n; i++) {   
        pre[i] = pre[i - 1] + a[i - 1].first;
    }
    i64 mx = -1;
    for(int i = 0; i < n; i++) {
        //cout << a[i].second * i + a[i].first - pre[i] << "\n";
         mx = max(mx, a[i].second * i + a[i].first - pre[i]);
    }
    //cout << mx << "\n";
    ans += mx;
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