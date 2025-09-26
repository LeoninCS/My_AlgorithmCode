#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    map<int,int> mp;
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
        sum += a;
    }
    vector<int> v;
    for(auto [x,y] : mp) {
        if(x % 2 == 1) v.push_back(y);
    }
    sort(v.begin(),v.end(), [](int a, int b) {
        return a > b;
    });
    i64 l = 0, r = 0;
    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) {
            l += v[i];
        } else {
            r += v[i];
        }
    }
    sum -= (l + r);
    l += sum / 2;
    r += sum / 2;
    cout << l << " " << r << "\n";
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