#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> se;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        se.insert(a);
    }
    int idx = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            idx++;
            if(!se.count(idx)) se.insert(idx);
        } else {
            idx++;
            while(se.count(idx)) idx++;
            se.insert(idx);
            idx++;
            while(se.count(idx)) idx++;
        }
    }
    cout << se.size() << "\n";
    for(auto x :se) cout << x << " ";
    cout << "\n";
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