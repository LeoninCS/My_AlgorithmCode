#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
     vector<int> v;
     for(int i = 0; i < n; i++)
     {
         if(a[i] == 1) v.push_back(i);
     }
     int k = v.size();
     int len = v[k - 1] - v[0] + 1;
     if(len <= x) cout << "YES\n";
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