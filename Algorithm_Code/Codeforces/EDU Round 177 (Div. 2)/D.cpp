#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

const i64 MOD = 998244353;

i64 bpow(i64 x, i64 p) 
{
	i64 res = 1;
	while(p) {
		if(p % 2) {
			res = (res * x) % MOD;
		}
		p >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}


i64 fact(i64 x) {
	i64 res = 1;
	for(i64 i = 1; i <= x; i++) {
		res = (res * i) % MOD;
	}
	return res;
}

void solve()
{
    vector<i64> cnt(26);
	i64 n = 0;
	i64 k = 0;
	for(int i = 0; i < 26; i++) {
		cin >> cnt[i];
	} 

	i64 s = accumulate(cnt.begin(), cnt.end(), 0LL);

	vector<i64> dp(s + 1);
	dp[0] = 1;

	for(int i = 0; i < 26; i++) {
		if(cnt[i] == 0) continue;
		for(i64 j = s - cnt[i]; j >= 0; j--) {
			dp[j + cnt[i]] = (dp[j + cnt[i]] + dp[j]) % MOD;
		}
	}

	i64 ans = dp[s / 2] * fact(s / 2) % MOD * fact((s + 1) / 2) % MOD;
	for(int i = 0; i < 26; i++) {
		ans = (ans * bpow(fact(cnt[i]), MOD - 2)) % MOD;
	}	
	cout << ans << "\n";
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