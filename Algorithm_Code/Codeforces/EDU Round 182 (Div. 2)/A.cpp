#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((pre[i] % 3 == (pre[j] - pre[i]) % 3 && pre[i] % 3 == (pre[n] - pre[j]) % 3) || 
                pre[i] % 3 != (pre[j] - pre[i]) % 3 && pre[i] % 3 != (pre[n] - pre[j]) % 3 && (pre[j] - pre[i]) % 3 != (pre[n] - pre[j]) % 3) {
                    //cout << pre[i] % 3 << " " << (pre[j] - pre[i]) % 3 << " " << (pre[n] - pre[j]) % 3 << "\n";
                    cout << i << " " << j << "\n";
                    return;
                }
            }
    }
    cout << 0 << " " << 0 << "\n";
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