#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n;
    cin >> n;
    int mir = 1e9, mic = 1e9, mxr = 0, mxc = 0;
    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        mir = min(mir, r);
        mic = min(mic, c);
        mxr = max(mxr, r);
        mxc = max(mxc, c);
    }
    int ans = 0;
    ans = max((mxr - mir + 1) / 2 ,(mxc - mic + 1) / 2);
    cout << ans << "\n";
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