#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	i64 a, b;
    cin >> a >> b;
    if((a + b) % 2 == 1 && !((b % 2 == 0 && (a * 2 + b / 2) % 2 == 0))) {
        cout << -1 << '\n';
        return;
    }
    if(b % 2 == 1) {
        cout << (i64)(a * b + 1) << "\n";
    } else {
        while(b % 2 == 0 && (a * 2 + b / 2) % 2 == 0) {
            b /= 2;
            a *= 2;
        }
        i64 x = 1;
        while(b % 2 == 0) {
            x *= 2;
            b /= 2;
        }
        a *= b;
        b = x;
        cout << a + b << "\n";
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