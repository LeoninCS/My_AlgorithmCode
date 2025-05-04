#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == 0) {
            cout << char(i + 'a') << '\n';
            return;
        }
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