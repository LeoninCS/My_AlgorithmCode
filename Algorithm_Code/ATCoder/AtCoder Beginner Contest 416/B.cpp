#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
    cin >> s;
    if(s == ".") s = "o";
    int idx = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '#') continue;
        if(i > 0 && s[i - 1] == '.') {
            s[i - 1] = 'o';
        }
        idx = i;
    }
    if(idx < s.size() - 1 && s[idx + 1] == '.') {
        s[idx + 1] = 'o';
    }
    cout << s << "\n";
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