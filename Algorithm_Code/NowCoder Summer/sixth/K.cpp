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
    int mx = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != a[0]) flag = false;
    }
    if(flag) {
        cout << 0 << "\n";
        return;
    }
    function<bool(int)> check = [&](int x) {
        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = (x - a[i] % x) % x;
        }
        b.push_back(-1);
        int cnt = 0;
        int l = 0;
        for(int i = 0; i <= n; i++) {
            if(b[i] != b[l]) {
                if(b[l] != 0) cnt++;
                l = i;
            }
        }
        //cout << x << " " << cnt << "\n";
        //for(int i = 0; i <= n; i++) cout << b[i] << " ";
        //cout << "\n";
        return cnt <= 1;
    };

    int ans = 0;
    for(int i = 1; i * i <= a[n - 1]; i++) {
        if(mx % i == 0) {
            if(check(i)) {
                ans = max(ans, i);
            }
            if(i * i != mx) {
                if(check(mx / i)) {
                    ans = max(ans, mx / i);
                }
            }
        }
    }
    for(int i = 1; i * i <= a[0]; i++) {
        if(mx % i == 0) {
            if(check(i)) {
                ans = max(ans, i);
            }
            if(i * i != mx) {
                if(check(mx / i)) {
                    ans = max(ans, mx / i);
                }
            }
        }
    }
    int g = 0;
    for(int i = 1; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    for(int i = 0; i <= a[0]; i++) {
        int xcq = __gcd(a[0] - i, g);
        ans = max(ans, xcq);
    }
    cout << ans << "\n";
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