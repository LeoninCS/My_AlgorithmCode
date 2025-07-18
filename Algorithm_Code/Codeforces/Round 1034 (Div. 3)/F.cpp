#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int pri[100005];

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1); 
    for(int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    for(int i = 2; i <= n; i++) {
        if(!pri[i]) {
            for(int j = 2; i * j <= n; j++) {
                ans[i * j] = i;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        int idx = ans[i]; 
        ans[i] = ans[idx];
        ans[idx] = i;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    for(int i = 2; i < 100005; i++) {
        if(pri[i]) continue;
        for(int j = 2; i * j < 100005; j++) {
            pri[i * j] = 1;
        }
    }

	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}