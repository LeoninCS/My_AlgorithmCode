#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

bool isprime(i64 a)
{
    if(a < 2) return false;
    for(i64 i = 2; i * i <= a; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

void solve()
{
	i64 x, k;
    cin >> x >> k;
    if(x == 1 && k == 2) {
        cout << "YES\n";
        return;
    }
    if(k != 1) {
        cout << "NO\n";
        return;
    }
    if(isprime(x)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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