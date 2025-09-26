#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum != n) {
        cout << 0 << "\n";
        return;
    }
    i64 ans = 0;
    int nn = n;
    for(int i = 0; i < n; i++) {
        
    }
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