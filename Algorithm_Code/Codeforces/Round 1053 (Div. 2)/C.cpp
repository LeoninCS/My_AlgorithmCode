#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<i64> a(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    i64 sum = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(i % 2 == 0) {
            sum -= a[i];
        } else {
            sum += a[i];
        }
    }
    vector<i64> ans;
    i64 cal = 0;
    for(int i = 0; i < n; i++) {
        cal -= a[i];
        cal += a[2 * n - i - 1];
        if(i % 2 == 0) {
            sum += a[i];
            sum -= a[2 * n - i - 1];
            ans.push_back(cal + sum);
        } else {
            sum -= a[i];
            sum += a[2 * n - i - 1];
            ans.push_back(cal - sum);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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