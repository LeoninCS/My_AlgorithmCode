#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    i64 ans = 0;

    if(a[n - 1]  - a[0] > k + 1 || (a[n - 1] - a[0] == k + 1 && a[n - 2]  - a[0] == k + 1)) {
        cout << "Jerry\n";
        return;
    }

    i64 sum = 0;    
    for(int i = 0; i < n; i++) {
            sum += a[i];
    }
    if(sum % 2 == 0) {
        cout << "Jerry\n";
    } else {
        cout << "Tom\n";
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