#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        for(int j = 0; j < n; j++) {
            if(a[j] == b) {
                a[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) cout << a[i] << " ";
    }
    
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