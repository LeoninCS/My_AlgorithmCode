#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> cnt(32, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            if(a[i] & (1LL << j)) {
                cnt[j]++;
            }
        }
    }
    i64 ans = 0;
    
    cout << ans / 2 << "\n";
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