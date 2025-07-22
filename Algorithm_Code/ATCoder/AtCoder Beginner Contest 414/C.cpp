
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

i64 a, n;
i64 ans = 0;

void check(i64 cur)
{
    if(cur > n) return;
    string s;
    i64 tem = cur;
    while(tem) {
        char ch = tem % a + '0';
        s.push_back(ch);
        tem /= a;
    }
    string ss = s;
    reverse(ss.begin(),ss.end());
    if(ss == s) {
        ans += cur;
        //cout << cur << "\n"; 
    }
}

void solve()
{
    cin >> a >> n;
    for(i64 i = 1; i <= 9; i++) {
        check(i);
    }
    for(i64 i = 1; i < pow(10,(int)(log10(n) + 1) / 2); i++) {
        for(i64 j = 0; j <= 9; j++) {
            i64 cur = i * 10 + j;
            i64 tem = i;
            while(tem) {
                cur = cur * 10 + tem % 10;
                tem /= 10;
            }
            check(cur);
        }
        i64 cur = i;
        i64 tem = i;
        while (tem) {
            cur = cur * 10 + tem % 10;
            tem /= 10;
        }
        check(cur);
    }
    cout << ans;
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