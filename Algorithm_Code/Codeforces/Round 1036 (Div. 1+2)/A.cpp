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
    int ans1 = a[0], ans2 = -1;
    for(int i = 0; i < n; i++) {
        ans1 = max(ans1,a[i]);
        if(a[i] < ans1) {
            ans2 = a[i];
            break;
        } 
    }
    if(ans2 == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << 2 << "\n";
        cout << ans1 << " " << ans2 << "\n";
    }
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