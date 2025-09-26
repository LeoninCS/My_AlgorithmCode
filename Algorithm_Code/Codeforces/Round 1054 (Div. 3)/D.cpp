#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	i64 n;
    cin >> n;
    string s;
    cin >> s;
    vector<i64> a, b;
    for(i64 i = 0; i < n; i++) {
        if(s[i] == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    vector<i64> prea;
    i64 cala = 0;
    for(i64 i = 0; i < a.size(); i++) {
        cala += (a[i] - i);
        prea.push_back(cala);
    }
    vector<i64> afta;
    cala = 0;
    for(i64 i = a.size() - 1; i >= 0; i--) {
        cala += (n - a.size() + i - a[i]);
        afta.push_back(cala);
    }
    reverse(afta.begin(), afta.end());
    vector<i64> preb;
    i64 calb = 0;
    for(i64 i = 0; i < b.size(); i++) {
        calb += (b[i] - i);
        preb.push_back(calb);
    }
     vector<i64> aftb;
    calb = 0;
    for(i64 i = b.size() - 1; i >= 0; i--) {
        calb += (n - b.size() + i - b[i]);
        aftb.push_back(calb);
    }
    reverse(aftb.begin(), aftb.end());
    i64 ans = 1e17;
    if(a.size() > 0) ans = min(ans, afta[0]);
    for(i64 i = 0; i < (i64)a.size(); i++) {
        if(i == a.size() - 1) {
            ans = min(ans, prea[i]);    
            continue;
        }
        ans = min(ans, prea[i] + afta[i + 1]);
    }
    if(b.size() > 0) ans = min(ans, aftb[0]);
     for(i64 i = 0; i < (i64)b.size(); i++) {
        if(i == b.size() - 1) {
            ans = min(ans, preb[i]);    
            continue;
        }
        ans = min(ans, preb[i] + aftb[i + 1]);
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	i64 T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}