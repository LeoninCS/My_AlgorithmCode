#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    bool cur = (s[0] == '1');
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') cnt++;
        if(i == 0) continue;
        if(s[i] == s[i - 1] && s[i] == '0') {
            cur = false;
        }
        if(s[i] == s[i - 1] && s[i] == '1') {
            if(cnt % 2 == 1 && cur) {
                ok = false;
            }
            cur = true;
            cnt = 0;
        }
    }
    if(s[n - 1] == '1' && cnt % 2 == 1 && cur) ok = false;
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
