#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n , k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	//1
	bool fi = true;
	int mx = 0,mi = 1e9+5;
	for(int i = 0; i < n; i++) {
		if(b[i] != -1) {
			fi = false;
			break;	
		}
		mx = max(mx,a[i]);
		mi = min(mi,a[i]);
	}
	if(fi) {
		//cout << mi << " " << k << " " << mx << endl;
		cout << mi + k - mx + 1 << endl;
		return;
	}
	//2
	set<int> se;
	for(int i = 0; i < n; i++) {
		if(b[i] != -1) se.insert(a[i] + b[i]);
	}
	if((int)se.size() > 1) {
		cout << 0 << endl;
		return;
	}
	int val = 0;
	for(int aa:se) val = aa;
	for(int i = 0; i < n; i++) {
		if(a[i] > val || a[i] + k < val) {
			cout << 0 << endl;
			return;
		}
	}
	cout << 1 << endl;
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