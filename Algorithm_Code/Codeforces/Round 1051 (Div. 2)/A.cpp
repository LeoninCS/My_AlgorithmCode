#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "YES\n";
        return;
    }
    bool ok = true;
    if(a[1] > a[0]) ok = true;
    else ok = false;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1] && !ok || a[i] < a[i - 1] && ok) {
            cout << "NO\n";
            return;
        }
        if(a[i] == n) ok = !ok;
    }
    cout << "YES\n";
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