#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;


i64 check(i64 x) {
    i64 cnt = 0;
    i64 len = 0;
    for(i64 i = 10; i <= x; i *= 10) {
        len++;
        cnt += len * 9 * pow(10, len - 1);
    }
    cnt += (len + 1) * (x - pow(10, len) + 1);
    return cnt;
}


void solve()
{
	i64 k;
    cin >> k;
    i64 l = 0, r = 1e16;
    while(l <= r) {
        i64 mid = (l + r) / 2;
        if(check(mid) > k) r = mid - 1;
        else l = mid + 1; 
    }
    //cout << r << "\n";
    i64 sub = k - check(r);
    vector<i64> dp(20, 0);
    i64 len = 0;
    for(i64 i = 10; i <= r; i *= 10) {
        len++;
        dp[len] = pow(10, len - 1) * 45 + dp[len - 1] * 10;
    }   
    i64 ans = 0;
    while(r) {
        i64 x = r / pow(10, len);
        //cout << x << " " << len << " " << r << "\n";
        if(x) ans += x * (x - 1) / 2 * pow(10, len) + dp[len] * x + x * (r % (i64)pow(10, len) + 1);
        r %= (i64)pow(10, len);
        len--;
        //cout << ans << "\n";
    }
    
    while(l) {
        if(l < pow(10, sub)) ans += l % 10;
        l /= 10;
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