#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int k,a,b,x,y;
    cin >> k >> a >> b >> x >> y;
    if(x < y) {
        swap(x,y);
        swap(a,b);
    }
    int ans = 0;
    int m1 = k - b;
    ans += max(0, m1) / y;
    k -= ans * y;
    if(k >= b) {
        ans++;
        k -= y;
    }
    int m2 = k - a;
    int cnt = max(0,m2) / x;
    ans += cnt;
    k -= cnt * x;
    if(k >= a) ans++;
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