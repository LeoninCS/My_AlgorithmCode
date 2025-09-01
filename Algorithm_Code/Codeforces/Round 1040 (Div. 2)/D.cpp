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
    for(int i = 0; i < n; i++) {
        int mi = 0, mx = 0;
        for(int j = 0; j < n; j++) {
            if(a[i] < a[j] && 2 * n - a[i] > a[j] && j < i) mi++;
            if(a[i] < a[j] && 2 * n - a[i] > a[j] && j > i) mx++;
        }
        if(mi > mx) a[i] = 2 * n - a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) ans++;
        }
        //cout << a[i] << " ";
    }
    //cout << "\n";
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