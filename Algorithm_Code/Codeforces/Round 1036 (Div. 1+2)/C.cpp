#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<i64> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<i64> v;
    for(int i = 0; i < n - 1; i++) {
        v.push_back(b[i] / __gcd(b[i],b[i + 1])); 
    }
    i64 lcm = v[0];
    for(int i = 1; i < v.size(); i++) {
        lcm = lcm * v[i] / __gcd(lcm, v[i]);
    }
    cout << lcm << "\n";
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