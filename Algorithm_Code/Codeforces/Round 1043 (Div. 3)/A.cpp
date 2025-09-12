#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    string a1 = "", a2 = "";
    for(int i = 0; i < m; i++) {
        if(c[i] == 'V') a1 += b[i];
        else a2 += b[i];
    }
    reverse(a1.begin(), a1.end());
    cout << a1 << a << a2 << "\n";
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