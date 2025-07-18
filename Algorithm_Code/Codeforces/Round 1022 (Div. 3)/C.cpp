#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> aa;
    aa.push_back(a[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i - 1]) {
            aa.push_back(a[i]);
        }
    }
    int k = aa.size();
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(i > 0 && aa[i - 1] > aa[i]) continue;
        if(i < k - 1 && aa[i + 1] > aa[i]) continue;
        ans++;
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