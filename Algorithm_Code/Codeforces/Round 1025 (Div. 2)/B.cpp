#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int ll(int a) 
{
    int cnt = 0;
    while(a > 1) {
        a += (a % 2);
        a /= 2;
        cnt++;
    }
    return cnt;
}

void solve()
{
	int a,b,c,d;
    cin >> a >> b >> c >> d;
    int aa = min(a - c + 1, c);
    int bb = min(b - d + 1, d);
    int ans = min(ll(a) + ll(bb),ll(b) + ll(aa));
    cout << ans + 1 << endl;
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