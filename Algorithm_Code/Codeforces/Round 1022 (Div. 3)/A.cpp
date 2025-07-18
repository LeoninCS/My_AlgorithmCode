#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    int ans = 0;
    if(n % 2 == 1) {
        n--;
        ans = (n * (n / 2 + 1)) / 2;
    }
    else {
        ans = (n * n / 2) / 2;
    } 
    cout << ans  + 1 << "\n";
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