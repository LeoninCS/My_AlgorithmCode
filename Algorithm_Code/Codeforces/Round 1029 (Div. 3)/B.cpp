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
    a[0] = 2;
    a[1] = 3;
    a[n - 1] = 1;
    for(int i = 2; i < n - 1; i++) {
        a[i] = i + 2;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
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