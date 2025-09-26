#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;

void solve()
{
	i64 h, d;
    cin >> h >> d;
    i64 ans = d;
    i64 l = 0, r = d;
    function<bool(i64)> cal = [&](i64 mid) -> bool {
        i64 div = d / (mid + 1), mod = d % (mid + 1);
        i64 res = mod * (div + 1) * (div + 2) / 2 + (mid - mod + 1) * div * (div + 1) / 2;
        if(res <= h + mid - 1) return true;
        else return false; 
    };
    while(l <= r) {
        i64 mid = l + (r - l) / 2;
        if(cal(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << d + ans << "\n";
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