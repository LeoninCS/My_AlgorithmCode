#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n , c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int idx = upper_bound(a.begin(), a.end(), c) - a.begin();
    idx--;
    int ans = n - idx - 1;
    int cnt = 0;
    for(int i  = idx; i >= 0; i--) {
        if(a[i] * pow(2,cnt) <= c) {
            cnt++;
        } else {
            ans++;
        }
    }
    cout << ans<< "\n";
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