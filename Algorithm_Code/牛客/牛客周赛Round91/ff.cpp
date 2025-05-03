#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int M = 998244353;

map<int,int> mp;

vector<pair<int,int>> pa(1000000);

void zhi(int n)
{
	int tem = n;
	for(int i = 2; i <= n; i++) {
		while(n % i == 0) {
			n /= i;
			mp[i]++;
			pa[tem].second = pa[tem].second / mp[i] * (mp[i] + 1);
			if(i % 2 == 1) pa[tem].first = pa[tem].first / mp[i] * (mp[i] + 1);	
		}
	}
}


i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}



void solve()
{
	int n = 0;
	cin >> n;
	int a = pa[n].first,b = pa[n].second;
	cout << a << " " << b << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	pa[1].first = 1;
	pa[1].second = 1;
	for(int i = 2; i <= 1000000; i++) {
		pa[i].first = pa[i - 1].first;
		pa[i].second = pa[i - 1].second;
		zhi(i);
	}
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}