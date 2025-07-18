#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<i64> a(n);
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    i64 num = x / sum;
    x -= num * sum;
    i64 cnt = n * num;
    i64 ans = 0;
    sum = 0;
    while(cnt <= n * k) {
        if(sum >= x)  {
            ans = n * k - cnt + 1;
            break;
        }
        sum += a[n - 1 - (cnt % n)];
        cnt++;
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