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
    map<char,int> mp;
    mp[s[0]]++;
    mp[s[n - 1]]++;
    for(int i = 1; i < n - 1; i++) {
        if(mp[s[i]] > 0) {
            cout << "Yes" << "\n";
            return;
        }
        mp[s[i]]++;
    }
    cout << "No" << "\n";
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