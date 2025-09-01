#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    i64 ans = 0;
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) continue;
        ans += max(0, a[i - 1] - a[i]);
        a[i - 1] = min(a[i - 1], a[i]);
        if(i + 1 < n) {
            ans += max(0,a[i + 1] + a[i - 1] - a[i]);
            a[i + 1] = min(a[i + 1], a[i] - a[i - 1]);
        }
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