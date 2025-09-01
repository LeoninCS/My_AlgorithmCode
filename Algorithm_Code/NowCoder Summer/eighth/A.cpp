#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

i64 qmi(i64 a, int b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int cal(i64 x) {
    int cnt = 0;
    while(x != 0) {
        cnt++;
        x /= 10;
    } 
    return cnt;
}

void solve()
{
    string s;
    cin >> s;
    if(s[0] == '-')  {
        bool flag = true;
        if(s[1] != '1') {
            cout << s.substr(0,1) << 1 << s.substr(1) << "\n";
            return;
        }
        for(int i = s.size() - 1; i >= 2; i--) {
            if(s[i] != '0') flag = false;
        }
        if(flag) cout << s << 1 << "\n";
        else cout << s.substr(0,1) << 1 << s.substr(1) << "\n";
    } else if(s[0] == '0') {
        cout << 10 << "\n";
    } else {
        int idx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' || s[i] == '0') {
                idx = i;
                break;
            }
        }
        cout << s.substr(0,idx) <<  1 << s.substr(idx) << "\n";
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