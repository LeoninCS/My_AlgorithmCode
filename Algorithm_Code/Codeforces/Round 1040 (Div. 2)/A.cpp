#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 0) sum += 1;
        else sum += a;   
    }
    cout << sum << "\n";
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