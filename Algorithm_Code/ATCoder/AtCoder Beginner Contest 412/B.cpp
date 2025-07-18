#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s, t;
    cin >> s >> t;
    set<char> se;
    for(char c : t) {
        se.insert(c);
    }
    for(int i = 1 ; i < s.size(); i++) {
        if(s[i] == toupper(s[i])) {
            if(se.count(s[i - 1]) == 0) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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