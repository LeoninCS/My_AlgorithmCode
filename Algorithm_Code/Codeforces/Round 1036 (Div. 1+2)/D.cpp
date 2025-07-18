#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> b(a);
    sort(b.begin(),b.end());
    set<int> se;
    i64 mx = 0;
    for(int i = 0; i < k - 1; i++) {
        se.insert(b[i]);
        mx = max(mx, b[i]);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(se.count(a[i])) ans.push_back(a[i]);
    }
    
    int l = 0, r = ans.size() - 1;
    int num = 0;
    while(l <= r) {
        if(ans[l] == ans[r]) {
            if(l == r) num += 1;
            else num += 2;
            l++;
            r--;
        } else {
            if(ans[l] != mx && ans[r] != mx) {
                cout << "NO\n";
                return;
            } else if(ans[l] == mx) {
                l++;
            } else if(ans[r] == mx){
                r--;
            }
        } 
    }
    if(num >= k - 1) cout << "YES\n";
    else cout << "NO\n";
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