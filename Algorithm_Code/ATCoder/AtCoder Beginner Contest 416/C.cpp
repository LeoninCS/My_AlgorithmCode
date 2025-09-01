#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<string> ans;
    function<void(int,string)> dfs = [&](int len,string str) {
        if(len == k) {
            ans.push_back(str);
            return;
        }
        for(int i = 0; i < n; i++) {
            dfs(len + 1, str + s[i]);
        }
    };
    dfs(0, "");
    sort(ans.begin(), ans.end());
    cout << ans[x - 1] << "\n";
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