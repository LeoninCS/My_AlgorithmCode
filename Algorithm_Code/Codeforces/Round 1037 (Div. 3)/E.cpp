#include<bits/stdc++.h>
#include <numeric>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<int> p(n), s(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    } 
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if(p[n - 1] != s[0]) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        int gcd = __gcd(p[i], s[i + 1]);
        if(gcd != s[0] || p[i] % p[i + 1] != 0) {
            cout << "NO\n";
            return;
        }
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