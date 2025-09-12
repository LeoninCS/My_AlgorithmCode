#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	i64 n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    } 
    for(auto &[x, y]: mp) {
        int k = y.size();
        if(k % x != 0) {
            cout << -1 << "\n";
            return;
        }
    }
    int num = 1;
    for(auto &[x, y]: mp) {
        int cnt = 0;
        for(auto &idx : y) {
            b[idx] = num;
            cnt++;
            if(cnt == x) {
                num++;
                cnt = 0;
            }
        }
    }
    for(auto &x : b) cout << x << " ";
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