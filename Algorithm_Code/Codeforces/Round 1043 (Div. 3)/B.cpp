#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	i64 n;
    cin >> n;
    vector<i64> ans;
    for(i64 i =10; i < n; i *= 10) {
        if(n % (i + 1) == 0) {
            ans.push_back(n / (i + 1));
        }
    }
    if(ans.size() == 0) {
        cout << 0 << "\n";
        return;
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(i64 x : ans) cout << x << " ";
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