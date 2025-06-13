#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<i64> v;
    map<i64, int> mp;
    for(int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        int cnt = 1;
        i64 y = 1;
        while(x) {
            if(x & 1 == 1) {
                mp[y]++;
                ans++;
            } 
            y <<= 1; 
            x >>= 1;
            cnt++;
        }
    }
    i64 mx = 1;   
    while(k) {
        i64 num = n - mp[mx];
        if(num * mx > k) {
            break;
        }
        k -= num * mx;
        ans += num;
        mx <<= 1;
    }
    while(k >= mx) {
        k -= mx;
        ans++;
    }
    cout << ans << '\n';
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