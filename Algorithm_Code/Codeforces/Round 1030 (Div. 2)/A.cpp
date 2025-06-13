#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
    cin >> n >> k;
    if(n == k) {
        for(int i = 0; i < n; i++) cout << 1;
        cout << '\n';
        return;
    }
    if(k == 0) {
        for(int i = 0; i < n; i++) cout << 0;
        cout << '\n';
        return;
    }
    cout << 1;
    k--;
    for(int i = 1; i < n - 1; i++) {
        if(i >= n - k - 1) cout << 1;
        else cout << 0;
    }
    cout << 0;
    cout << '\n';
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