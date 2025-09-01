#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    int mx = 0, x = -1;
    for(int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n << " ";
        for(int j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        cout.flush();
        int k;
        cin >> k;
        a[k].push_back(i);
        if(k > mx) {
            mx = k;
            x = i;
        }
    }
    vector<int> ans;
    while(1) {
        ans.push_back(x);
        if(mx == 1) break;
        for(int nxt: a[mx - 1]) {
            cout << "? " << x << " " << 2 << " " << x << " " << nxt << endl;
            cout.flush();
            int k = 0;
            cin >> k;
            if(k == 2) {
                mx--;
                x = nxt;
                break;
            }
        }
    }
    cout << "! " << ans.size() << " ";
    for(int node:ans) cout << node << " ";
    cout << endl;
    cout.flush();
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