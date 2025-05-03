#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> gra(n);
	vector<int> c(m, 0),r(n, 0);
	
	int cnt = 0;
	for(int i = 0; i < n; i++) cin >> gra[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(gra[i][j] != '1') continue; 
			r[i]++;
			c[j]++;
			cnt++;
		}
	}	
	if(cnt != 0 && cnt != 2 * m && cnt != 2 * n && cnt != n + m - 2) {
		cout << cnt;
		cout << "NO" << endl;
		return;
	}
	//1
	bool first = true;
	for(int i = 0; i < n; i++) if(r[i] != 0) first = false;
	for(int i = 0; i < m; i++) if(c[i] != 0) first = false;
	if(first) {
		cout << "YES" << endl;
		return;
	}
	//2
	int cnt0 = 0,cnt1 = 0;
	for(int i = 0; i < n; i++) {
		if(r[i] == 0) cnt0++;
		if(r[i] == m) cnt1++;
	}
	if(cnt0 == n - 2 && cnt1 == 2) {
		cout << "YES" << endl;
		return;
	}
	//3
	cnt0 = 0,cnt1 = 0;
	for(int i = 0; i < m; i++) {
		if(c[i] == 0) cnt0++;
		if(c[i] == n) cnt1++;
	}
	if(cnt0 == m - 2 && cnt1 == 2) {
		cout << "YES" << endl;
		return;
	}
	
	//4
	vector<pair<int,int>> v;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(gra[i][j] == '1') continue;
			if(i - 1 >= 0 && gra[i - 1][m] == '0') continue;
			if(i + 1 < n && gra[i + 1][m] == '0') continue;
			if(j - 1 >= 0 && gra[i][j - 1] == '0') continue;
			if(j + 1 < m && gra[i][ j + 1] == '0') continue;
			v.push_back({i,j}); 
		}
	}
	for(int i = 0; i < (int)v.size(); i++) {
		if(r[v[i].first] == n - 1 && c[v[i].second] == m - 1) {
		cout << "YES" << endl;
		return;
	}
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
