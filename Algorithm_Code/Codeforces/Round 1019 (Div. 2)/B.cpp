#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    string s;
    cin >> n >> s;
    int idx1 = 0, idx2 = n - 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;    
        else {
            idx1 = i;
            break;
        }
    }
    for(int i = idx1; i < n - 1; i++) {
        if(s[i] == '0' && s[i + 1] == '1') {
            idx2 = i;
            break;
        }
    }
    string s1 = s.substr(0, idx1);
    string s2 = s.substr(idx1, idx2 - idx1 + 1);
    string s3 = s.substr(idx2 + 1, n - idx2 - 1);
    reverse(s2.begin(), s2.end());
    s = s1 + s2 + s3;
    char cur = '0';
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == cur) {
            ans++;
        } else {
            ans += 2;
            if(cur == '0') {
                cur = '1';
            } else {
                cur = '0';
            }
        }
    }
    //cout << s << '\n';
    cout << ans << '\n';
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