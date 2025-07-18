#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

const i64 mod = 998244353;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    int cnt = 0;
    i64 r = n;
    for(int i = 0; i < n; i++) {
        if(a[i] == i + 1) {
            cnt++;
            r--;
            continue;
        }
        //cout << i + 1 << " " << a[a[i] - 1] << " " << r << "\n";
        if(i + 1 == a[a[i] - 1]) {
            r -= 2;
        }
    }
    //cout << cnt << " " << r << " ";
    if(cnt == 2) {
        cout << 1 << "\n";
    } else if(cnt == 1) {
        r = r % mod;
        cout << r << "\n";
    } else {
        i64 ans = r - 1;
        for(i64 i = r - 2; i >= 2; i -= 2) {
            ans = (ans + i) % mod;
        }
        cout << ans << "\n";
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