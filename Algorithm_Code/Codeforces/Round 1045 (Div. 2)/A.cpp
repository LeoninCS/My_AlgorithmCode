#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(a < b) a = b;
    if((n - a) % 2 == 0 && (n - b) % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
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