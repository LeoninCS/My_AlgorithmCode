#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    i64 a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(k % 2 == 1) {
            if(a % 2 == 0) cout << a << " ";
            else cout << a + k << " ";
            continue;
        }
        i64 x = a % (k + 1);
        i64 ans = x * k + a;
        cout << ans << " ";
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