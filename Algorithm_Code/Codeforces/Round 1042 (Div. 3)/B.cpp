#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        if(i % 2 == 0) cout << -1 << " ";
        else cout << 3 << " "; 
    }
    if(n % 2 == 1) cout << -1 << " ";
    else cout << 2 << " ";
    cout << "\n";
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