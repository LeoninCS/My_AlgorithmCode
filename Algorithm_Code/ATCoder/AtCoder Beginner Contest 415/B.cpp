#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string s;
    cin >> s;
    vector<int> ans;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '#') ans.push_back(i + 1);
    }
    for(int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] << "," << ans[i + 1] << "\n";
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