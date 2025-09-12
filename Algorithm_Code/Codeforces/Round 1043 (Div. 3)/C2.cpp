#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	i64 n, k;
    cin >> n >> k;
    vector<i64> cnt(20, 0);
    for(int i = 0; i < 20; i++) {
        cnt[i] = n % 3;
        n /= 3;
    }
    int sum  = 0;
    for(int i = 0; i < 20; i++) {
        sum += cnt[i];
    }
    if(sum > k) {
        cout << -1 << "\n";
        return;
    }
    k -= sum;
    for(int i = 19; i >= 1; i--) {
        if(k < 2) break;
        i64 sub = min(cnt[i], k / 2);
        cnt[i] -= sub;
        cnt[i - 1] += sub * 3;
        k -= sub * 2;
    }
    i64 ans = 0;
    for(int i = 0; i < 20; i++) {
        ans += cnt[i] * (pow(3, i + 1) + i * pow(3, max(0, i - 1)));
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