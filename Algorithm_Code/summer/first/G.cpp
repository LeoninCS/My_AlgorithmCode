#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s.push_back('0');
    while(q--) {
        int x;
        string t;
        cin >> t >> x;
        string tt(x - 1,'0');
        t = tt + t;
        t.push_back('1');
        int len = min(s.size(), t.size());
        i64 cnt = 0;
        i64 ans = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == t[i]) cnt++;
            else {
                ans += (cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }
        cout << ans << "\n";
    }
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