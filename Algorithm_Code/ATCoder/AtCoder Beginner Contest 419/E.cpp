#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    int ans = 0;
    int re = 0;
    for(int i = 0; i < n - l; i++) {
        int sum = 0;
        for(int j = i; j < i + l; j++) {
            sum += a[j];
        }
        int ne = m - sum % m;
        //cout << re << " " << ne << "\n"; 
        ans += max(0, ne - re);
        re = ne;
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}