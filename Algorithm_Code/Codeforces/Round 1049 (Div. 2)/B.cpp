#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


i64 cal(i64 x) {
    i64 res = 0;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}

void solve()
{
	i64 x;
    cin >> x;
    for(i64 i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            i64 y = x / i;
            i64 len = cal(y);
            if((x * (i64)(pow(10, len)) + y) % (x + y) == 0) {
                cout << y << "\n";
                return;
            }   
        }
    } 
    for(int i = 1; i <= 10; i++) {
        i64 y = i * x;
        i64 len = cal(y);
        if((x * (i64)(pow(10, len)) + y) % (x + y) == 0) {
            cout << y << "\n";
            return;
        }
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