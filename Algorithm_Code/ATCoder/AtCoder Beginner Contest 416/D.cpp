#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] %= m;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    i64 ans = 0;
    int l = 0, r = n - 1;
    while(l < n && r < n) {
        if(a[l] + b[r] < m) {
            l++;
        } else {
            ans += (a[l] + b[r]) % m;
            a[l] = 0;
            b[r] = 0;
            l++;
            r--;
        }
    } 
    for(int i = 0; i < n; i++) {
        ans += a[i];
        ans += b[i];
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