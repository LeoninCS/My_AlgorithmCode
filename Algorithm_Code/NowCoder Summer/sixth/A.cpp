#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
const i64 mod =  998244353;

vector<i64> dp(5e5 + 10, -1);

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
	int n;
    cin >> n;
    cout << (dp[n] + mod) % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
    dp[1] = 1;
    dp[2] = 9;
    for(int i = 3; i <= 5e5; i++) {
        dp[i] = qmi(i, 3) % mod + (dp[i - 1] * i - dp[i - 2]) % mod;
    }

	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}