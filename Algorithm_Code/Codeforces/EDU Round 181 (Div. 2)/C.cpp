#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 l, r;
    cin >> l >> r;
    i64 ans1 = l, ans2 = r;
    i64 a[4] = {2, 3, 5, 7};
    i64 b[6] = {6, 10, 14, 15, 21, 35};
    i64 c[4] = {30, 42, 105, 70};
    i64 d[1] = {210};
    for(int i = 0; i < 4; i++) {
        ans1 -= l / a[i];
        ans2 -= r / a[i]; 
    }
    
    for(int i = 0; i < 6; i++) {
        ans1 += l / b[i];
        ans2 += r / b[i];
    }
    for(int i = 0; i < 4; i++) {
        ans1 -= l / c[i];
        ans2 -= r / c[i];
    }
    ans1 += l / d[0];
    ans2 += r / d[0];
    i64 ans = ans2 - ans1;
    if(l % 2 && l % 3 && l % 5 && l % 7) ans++;
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