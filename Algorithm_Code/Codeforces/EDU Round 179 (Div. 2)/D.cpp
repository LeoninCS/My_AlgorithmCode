#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        int x;
        if(i % 2 == 0) x = i / 2;  
        else  x = m - 1 - i / 2;
        int y = m - 1 - x;
        cout << a[x] << " " << a[y] << " " << a[x] << " " << a[y] << " " << a[x] << " " << a[y] << "\n";
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