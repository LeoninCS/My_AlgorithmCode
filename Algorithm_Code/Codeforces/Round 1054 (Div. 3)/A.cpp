#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 0) cnt0++;
        if(a == -1) cnt1++; 
    }
    int ans = cnt0 + 2 * (cnt1 % 2);
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