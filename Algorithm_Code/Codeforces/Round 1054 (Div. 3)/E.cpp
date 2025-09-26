#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	i64 n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(0);
    i64 ans = 0;
    map<i64,i64> mp;
    map<i64,i64> mpx;
    i64 idx = 0, cnt = 0;
    i64 x = 1000000;
    for(i64 i = 0; i <= n; i++) {
        mp[a[i]]++;
        if(mp[a[i]] == 1) cnt++;
        if(x == 1000000) {
            mpx[a[i]]++;
        }
        if(cnt == k && x == 1000000) {
            x = i;
        }
        while(cnt > k) {
            ans += max(0LL, min(i - 1, idx + r - 1) - max(x, idx + l - 1) + 1);
            mp[a[idx]]--;
            mpx[a[idx]]--;
            if(mp[a[idx]] == 0) cnt--;
            if(mpx[a[idx]] == 0) {
                while(1) {
                    x++;
                    mpx[a[x]]++;
                    if(mpx[a[x]] == 1) break;
                }
            }
            idx++;
        }
    }
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