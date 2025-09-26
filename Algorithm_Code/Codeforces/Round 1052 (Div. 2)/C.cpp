#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;

/*
function find(int x):    
l := 1    r := n    
while l <= r:        let m be a random integer between l and r,inclusive        
if p[m] == x            
return m        
if p[m] > x:            
r := m - 1        
else:            
l := m + 1    
return undefined     // not found
*/

void solve()
{
	int n;
    cin >> n;
    string s;
    cin >> s;
    s = s + '1';
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }
    vector<pii> v;
    int l = -1;
    for(int i = 0; i <= n; i++) {
        if(s[i] == '1' && l == -1) continue;
        if(s[i] == '0' && l == -1) l = i;
        if(s[i] == '1' && l != -1) {
            v.push_back({l,i - 1});
            l = -1;
        }
    }
    for(auto [x,y] : v) {
        if(x == y) {
            cout << "NO\n";
            return;
        }
        for(int i = x; i <= y; i++) {
            ans[i] = x + y - i + 1;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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