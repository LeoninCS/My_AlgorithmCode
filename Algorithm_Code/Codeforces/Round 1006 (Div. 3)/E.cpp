#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> v;
void solve()
{
	int k = 0; 
	cin >> k;
	if(k == 0) {
		cout << 0 << endl;
		return;
	}
	int l = 1, r = v.size();	
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(v[mid] >= k) r = mid - 1;
		else l = mid + 1;
	}
	int cnt = l - 1;
	k -= v[cnt];
    int ans = 1;
    cout << cnt + 1 + k << endl;
    for(int i = 0; i < cnt1 + 1; i++) {
        cout << 1 << " " << ans << endl;
        ans++;
    }
	for(int i = 2; i < k + 2; i++) cout << i << " " << i - 1 << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int add = 0;
	int pb = 0;
	while(pb <= 100128) {
		pb += add;
		v.push_back(pb);
		add++;
	}
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}