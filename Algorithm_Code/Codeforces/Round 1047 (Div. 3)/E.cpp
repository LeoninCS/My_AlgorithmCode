#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    map<i64,i64> mp;
    for(i64 i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    i64 val = 0;
    i64 va = 0;
    for(auto & [x, y] : mp) {
        if(x == va && y == 1) {
            va++;
        }
        if(x == val) {
            val++;
        } else break;
    }
    if(k == 1) {
        i64 ans = 0;
        for(int i = 0; i < n; i++) {
            if(mp[a[i]] == 1 && a[i] < val) ans += a[i];
            else ans += val;
        }
        cout << ans << "\n";
        return;
    }
    if(va == val) {
        i64 ans = 0;
        if(n - va == 1) ans = va * (va - 1) / 2 + (n - va) * va; 
        else ans = va * (va - 1) / 2 + (n - va) * (va + (k + 1) % 2);
        cout << ans << "\n";
        return;
    } 
    //cout << "va" << va << "\n";
    i64 ans = va * (va - 1) / 2 + (n - va) * (va + k % 2);
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