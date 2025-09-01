#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    string s;
    cin >> n >> s;
    if(n > 2 && s[n - 3] == 't' && s[n - 2] == 'e' && s[n - 1] == 'a') cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}