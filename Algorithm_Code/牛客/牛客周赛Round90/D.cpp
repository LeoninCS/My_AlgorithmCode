#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	auto check = [&](i64 mid) -> i64 {
		i64 res = 0;
		i64 cnt = 0, cnt2 = 0, cnt5 = 0; 
		for(int i = 0; i < n; i++) {
			string s = to_string(a[i]);
			int len = s.size();
			for(int idx = 0; idx < len; idx++) {
				if(s[idx] == '2') cnt2++;
				if(s[idx] == '5') {
					cnt += cnt2;
				}
				if(cnt > mid) {
					res++;
					cnt = 0;
					cnt2 = 0;
					i--;
					break;
				}
			}
		}
		return res + 1;
	};
	i64 l = 0, r = 1e18;
	while(l <= r) {
		i64 mid = (r - l) / 2 + l;
		if(check(mid) <= k) r = mid - 1;
		else l = mid + 1; 
	}
	cout << l;
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