#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n, m;
	cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    if(m == 1) {
        cout << n - a[0] + 1 << "\n";
        return;
    }
    int ok = false;
    for(int i = 1; i < m; i++) {
        if(a[i] <= a[i - 1]) {
            ok = true;
            break;
        }
    }
    if(ok) {
        cout << 1 << "\n";
        return;
    }
    cout << n - a[m - 1] + 1 << "\n";
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