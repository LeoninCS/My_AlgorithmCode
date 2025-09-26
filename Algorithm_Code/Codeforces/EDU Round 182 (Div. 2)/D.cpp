#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	i64 n, y;
    cin >> n >> y;
    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    } 
    int mx = -1;
    for(int i = 0; i < n; i++) mx = max(mx, c[i]);
    vector<int> a(mx + 1, 0);
    vector<i64> b(mx + 1, 0);
    for(int i = 0; i < n; i++) {
        if(c[i] <= mx) a[c[i]]++;
    }
    if(mx == 1) {
        cout << n << "\n";
        return;
    }
    for(int i = 1; i <= mx; i++) {
        b[i] = b[i - 1] + a[i];
    }
    i64 ans = -1e18;
    for(int i = 2; i <= mx; i++) {
        i64 sum = 0, cnt = 0;
        int j = 1;
        while(1) {
            int l = (j - 1) * i + 1, r = min(i * j, mx);
            if(l > mx) break;
            sum += (b[r] - b[l - 1]) * j;
            if(j <= mx) {
                cnt += min(b[r] - b[l - 1], (i64)(a[j]));
            }
            j++;
        }
        i64 w = (n - cnt) * y;
        ans = max(ans, sum - w);
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